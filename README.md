# MultiLevel-Queue-Scheduling-based-Hospital-Management-System
Multi-level queue scheduling algorithm is used to schedule the hospital treatments according to the priority of different departments like Out Patient Department and Emergency Department. The emergency department is given a higher priority over the outpatient department (OPD). Individual queues are formed for the treatments of patients in respective departments. 
As shown in BLOCK DIAGRAM, the OPD is at level 1 in priority whereas emergency is at level 0 which is a higher priority. 
No treatment will be done in OPD as long as the emergency department has treatments pending. 
The outpatient department individually follows FCFS whereas the emergency department follows Priority queue scheduling as one particular case can be more critical than another.
It should be noted that both the departments are non-preemptive so none of the treatments, be it from opd or emergency cannot be interrupted in between.
