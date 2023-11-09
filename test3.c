#define _GNU_SOURCE     // GNU 확장 기능을 사용하도록 정의
#include <stdio.h>
#include <stdlib.h>     // exit
#include <unistd.h>     // fork, pipe, close
#include <time.h>       // clock_gettime
#include <sys/syscall.h>    // syscall
#include <sched.h>      // sched_setscheduler, sched_get_priority_max
#include <sys/resource.h>   // setpriority
#include <string.h>     // memset
#include <sys/wait.h>   // waitpid
#include <errno.h>      // perror

// 각 자식 프로세스의 실행 결과를 출력
void printResult(pid_t pid, struct timespec start, struct timespec end, double elapsedTime, int nice) {
	// 프로세스 ID 출력
    printf("PID: %d ", pid);
	// CFS_NICE일 때만 NICE 값 출력
    // CFS_NICE가 아닐 때 nice == -1
    if (nice != -1) printf("| NICE : %d ", nice);

	char buf[100];
	struct tm tstart, tend;

    // 시작 시간을 로컬 시간 형식으로 변환
	localtime_r(&start.tv_sec, &tstart);
    // 종료 시간을 로컬 시간 형식으로 변환
	localtime_r(&end.tv_sec, &tend);

    // 프로세스 시작 시간 출력
	strftime(buf, sizeof(buf), "%H:%M:%S", &tstart);
	printf("| Start time: %s.%09ld ", buf, start.tv_nsec);

    // 프로세스 종료 시간 출력
	strftime(buf, sizeof(buf), "%H:%M:%S", &tend);
	printf("| End time: %s.%09ld ", buf, end.tv_nsec);

    // 소요 시간 출력
	printf("| Elapsed time: %f\n", elapsedTime);
	fflush(stdout);
}

// SCHED_PIPO, SCHED_RR 스케줄링 정책 설정
void setSchedulingPolicy(int policy, int priority, int timeSlice, int pid) {
	struct sched_param param;   // 스케줄링 매개변수 정의하기 위한 구조체
	param.sched_priority = priority;    // 프로세스 우선순위 설정

    // 스케줄링 정책 설정
    // pid : 변경하려는 프로세스의 id
    // policy : 적용하려는 스케줄링 정책 (SCHED_FIFO, SCHED_RR)
	if (sched_setscheduler(pid, policy, &param) == -1) {
		perror("sched_setscheduler");
		exit(EXIT_FAILURE);
	}
    // SCHED_RR인 경우, time slice 설정
	if (policy == SCHED_RR) {
		FILE *fp;   //FILE 포인터 선언

        // 파일 이름 저장
		const char *filename = "/proc/sys/kernel/sched_rr_timeslice_ms";
        fp = fopen(filename, "w");   // 쓰기모드로 파일 열기
		if (fp == NULL) {
			perror("Error opening file");   // fopen 실패 시 에러 출력
			exit(EXIT_FAILURE);
		}
		
		fprintf(fp, "%d", timeSlice);       // 파일에 timeSlice값을 정수로 기록
		fclose(fp);     // 파일 닫기
	}
}

int main() {
    // CPU 코어 개수 1개로 제한
    // CPU 0에 현재 프로세스를 바인딩
	cpu_set_t set;
	CPU_ZERO(&set);
	CPU_SET(0, &set);
	if (sched_setaffinity(0, sizeof(cpu_set_t), &set) == -1) {
		perror("sched_setaffinity");
		exit(EXIT_FAILURE);
	}

    // 스케줄링 정책 입력 받기 위한 문구 출력
	printf("Input the Scheduling Polity to apply:\n1. CFS_DEFAULT\n2. CFS_NICE\n3. RT_FIFO\n4. RT_RR\n0. Exit\n");

    int pip[21][2];     // 파이프 배열 선언
	pid_t child_pid[21];    // 자식 프로세스 pid값 저장하는 배열
    
    // 21개의 Named_pipe(부모, 자식 프로세스 간 소통) 생성
	for (int i = 0; i < 21; i++) {
		if (pipe(pip[i]) == -1) {
			perror("pipe");
			exit(EXIT_FAILURE);
		}
	}

	int option, nice = -1, timeSlice = -1, policy;
    // 스케줄링 정책 입력받기
    // 1. CFS_DEFAULT
    // 2. CFS_NICE
    // 3. RT_FIFO
    // 4. RT_RR
	scanf("%d", &option);
	if (!option) return 0;  // 0. exit
	if (option < 0 || option > 4) {     // 그 외 값 입력 시 종료
		return 0;
	}

	int priority = 0;

    // 입력 옵션에 따라 스케줄링 정책 및 우선순위 설정
    // CFS_DEFAULT는 리눅스 스케줄링의 기본값이므로 따로 설정 X
    // CFS_NICE는 기본 스케줄링에 nice값만 변경하는 것이므로 따로 설정 X
	switch(option) {
		case 3:		//RT_FIFO
			policy = SCHED_FIFO;
            // sched_get_priority_max() : 특정 스케줄링 정책에 대해
            // 사용 가능한 최대 우선 순위 값 반환
            // 반환값 = 스케줄링 정책에서 사용할 수 있는 가장 높은 우선순위
			priority = sched_get_priority_max(SCHED_FIFO);
			break;
		case 4:		//RT_RR
			policy = SCHED_RR;
			priority = sched_get_priority_max(SCHED_RR);

            // RT_RR의 경우, 적용할 timeSlice도 입력 받기
			printf("Input the Time Slice to apply(10, 100, 1000): ");
			scanf("%d", &timeSlice);
			break;
	}

    // 작업 시작 시간, 종료 시간 저장하기 위한 구조체
	struct timespec start, end;

	for (int i = 0; i < 21; i++) {
        // 21개의 자식 프로세스 생성
		child_pid[i] = fork();
        
        // CFS_NICE의 경우 처음 7개는 19, 다음 7개는 0, 다음 7개는 -20으로 nice값 변경
		if (option == 2) {
			if (i < 7) nice = 19;
			else if (i < 14) nice = 0;
			else nice = -20;
		}

        // 자식 프로세스 수행
		if (child_pid[i] == 0) {
            // CPU 코어 1개로 제한
            // CPU 친화도 설정 sched_setaffinity(pid, 타입 크기 지정, 어느 cpu 코어에 할당할 것인지)
			if (sched_setaffinity(0, sizeof(cpu_set_t), &set) == -1) {
				perror("sched_setaffinity");
				exit(EXIT_FAILURE);
			}

            // RT_FIFO, RT_RR 정책의 경우 스케줄링 설정 함수 호출
			if (option == 3 || option == 4) {
				setSchedulingPolicy(policy, priority, timeSlice, getpid());
			}
            // CFS_NICE 정책의 경우 기존 스케줄링 정책에서 nice값 변경
			if (option == 2) {
                // PRIO_PROCESS : 현재 프로세스의 우선순위를 변경하겠다는 것
                // 0 : 현재 프로세스의 id
                // nice : 지정할 nice값, 낮을 수록 높은 우선 순위
				if (setpriority(PRIO_PROCESS, 0, nice) < 0) {
					perror("Fail setpriority");     // 실패할 경우 출력
					exit(EXIT_FAILURE);
				}
			}

            // 자식 프로세스 : 실행 시간 write 해야하니까
            // read 쪽 pip[i][0] 닫기
			if (close(pip[i][0]) == -1) {
				perror("Fail read pipe in child process");  //닫기 실패할 경우
				exit(EXIT_FAILURE);
			}

            // 현재 시간 측정 (시작 시간)
			clock_gettime(CLOCK_REALTIME, &start);

            // 배열 곱셈 연산 수행
			int count = 0, k, l, j;
			int result[102][102], A[102][102], B[102][102];
			memset(result, 0, sizeof(result));
			memset(A, 0, sizeof(A));
			memset(B, 0, sizeof(B));
			while(count < 100) {
				for (k = 0; k < 100; k++) {
					for(l = 0; l < 100; l++) {
						for(j = 0; j < 100; j++) {
							result[k][j] += A[k][l] * B[l][j];
						}
					}
				}
				count++;
			}

            // 현재 시간 측정 (종료 시간)
			clock_gettime(CLOCK_REALTIME, &end);
            // 작업 수행하는 데 걸린 시간 초 단위로 계산
			double elapsedTime = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

            // 수행 시간 파이프에 write
            // 부모 프로세스로 전송하기 위함
			write(pip[i][1], &elapsedTime, sizeof(elapsedTime));
            //write 이후 write 쪽 pip[i][1] 닫기
			close(pip[i][1]);

            // 결과 출력하는 함수 호출
            // 프로세스의 pid값, 시작시간, 종료시간, 실행시간, nice값 전달
			printResult(getpid(), start, end, elapsedTime, nice);

            // 성공적으로 작업 마친 후 자식 프로세스 종료
			exit(EXIT_SUCCESS);

		} else if (child_pid[i] < 0) {      // fork 실패할 경우 종료
			perror("fail fork");
			exit(EXIT_FAILURE);
		}
	}

	//부모 프로세스 수행
	double total_elapsed = 0;   // 모든 자식 프로세스 수행 시간의 합
	for (int i = 0; i < 21; i++) {
		int status;
		pid_t wpid;

        // 자식 프로세스 종료될 때까지 wait
		do {
			wpid = waitpid(child_pid[i], &status, 0);
		} while (wpid == -1);

        // 자식 프로세스가 정상적으로 종료되었는지 확인
		if (WIFEXITED(status)) {
			double elapsed;

            // 부모 프로세스 : 실행시간 read 해야하니까
            // write 쪽 pip[i][1] 닫기
			close(pip[i][1]);

            // 파이프를 통해 자식 프로세스의 실행 시간 읽기
			if (read(pip[i][0], &elapsed, sizeof(elapsed)) > 0) {
				total_elapsed += elapsed;
			} else {    // 실패 시 오류 메시지 출력 후 종료
				perror("Fail read in parent process");
				exit(EXIT_FAILURE);
			}
		}

        // read 이후 read 쪽 pip[i][0] 닫기
		close(pip[i][0]);
	}

    // 평균 실행 시간 = (자식 프로세스들의 실행 시간 총합) / (자식 프로세스 개수)
	double avgTime = total_elapsed / 21;

    // 적용된 스케줄링 정책 출력
	printf("Scheduling Policy: ");
	switch(option) {
		case 1:
			printf("CFS_DEFAULT | ");
			break;
		case 2:
			printf("CFS_NICE | ");
			break;
		case 3:
			printf("RT_FIFO | ");
			break;
		case 4:
			printf("RT_RR | ");
			break;
	}
    // RT_RR의 경우 timeSlice도 출력
	if (timeSlice != -1) printf("Time Quantum: %d ms | ", timeSlice);
    // 구해놓은 평균 실행 시간 출력
	printf("Average elapsed time: %f\n", avgTime);
}
