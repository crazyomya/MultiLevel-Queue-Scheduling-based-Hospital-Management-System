# Multi-Level Queue Scheduling-Based Hospital Management System

The Multi-Level Queue Scheduling algorithm is employed to efficiently schedule hospital treatments, prioritizing different departments such as the Outpatient Department (OPD) and Emergency Department. In this system, the Emergency Department is granted a higher priority than the OPD, ensuring critical cases receive prompt attention.

## Key Features

- **Multiple Priority Levels**: The system classifies treatments into distinct priority levels. Emergency treatments are given the highest priority (Level 0), while OPD treatments are placed at a lower priority (Level 1).

- **Individual Queues**: Separate queues are maintained for the treatment of patients in their respective departments, ensuring organized and efficient handling.

- **Priority Management**: The Emergency Department utilizes Priority Queue Scheduling to address critical cases promptly, acknowledging that some cases may require immediate attention over others.

- **Non-Preemptive Approach**: Both the OPD and Emergency Department operate on a non-preemptive basis. Once a treatment begins, it is not interrupted until completion.

## Block Diagram

![BLOCK DIAGRAM](https://github.com/crazyomya/MultiLevel-Queue-Scheduling-based-Hospital-Management-System/assets/92091486/f4f05bad-a877-4b1f-a5cd-04b1d88addd2)


## Operation Details

- No treatments are initiated in the OPD if the Emergency Department has pending treatments.

- The OPD follows a First-Come-First-Serve (FCFS) approach, ensuring fairness in treatment scheduling.

- The Emergency Department, on the other hand, employs Priority Queue Scheduling to address critical cases immediately, as some cases may require higher priority.

This Hospital Management System streamlines treatment scheduling, ensuring that critical cases receive the attention they require while maintaining a fair and organized approach to outpatient treatments.

---

Feel free to customize this README with specific implementation details, setup instructions, or additional project-specific information as needed.
