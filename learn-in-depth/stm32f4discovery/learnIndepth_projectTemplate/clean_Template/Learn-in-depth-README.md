    /*
 * AUTOSAR IN Depth Materials
 * www.learn-in-depth.com
 * Eng.Keroles Shenouda
 * eng.keroles.karam@gmail.com
 *
 *   
 */
	
	Initial State (Autostart): Extended tasks can be set to start automatically with the system boot-up (autostart), which seems to be the case for Task T1. This is correct.

    Task Activation: ActivateTask(task2) correctly changes the state of Task T2 from "Suspended" to "Running", which preempts Task T1 due to its higher priority. This is a correct transition.

    Preemption: When a higher priority task (like T2 or T3) is activated, it preempts the currently running lower priority task (like T1), which is correctly shown as moving to the "Ready" state.

    Termination: TerminateTask() is correctly used to terminate the running task, after which it transitions back to the "Suspended" state. This is the correct behavior for terminating a task in OSEK/VDX.

    Task Priorities: The diagram reflects that higher priority tasks preempt lower priority ones. Task T3, which has the highest priority, preempts Task T2, and Task T2 preempts Task T1 when they are activated. This correctly illustrates OSEK/VDX's priority-based preemption mechanism.

The system is based scheduled with a 1ms SysTick `SystemCounter`.


open CMD 
1- Update PATHs 
learnInDepth_SetEnv.bat

2-Set the oil file to "learnInDepth_build.bat"

3-Configure And Build 
learnInDepth_build.bat

3-Run on Keil Uvision Project 
