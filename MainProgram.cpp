#include <bits/stdc++.h>
using namespace std;

#include <unistd.h>

#include <iostream>
#include <cstdlib>

struct patient
{
    int patient_id, arrival_time, treatment_time, priority = 25, depart_time = -1, wait_time = -1, tat, remainder_time;
    string name, department;
};

patient patient_list[50];

void print_report(struct patient pl[], int size)
{

    cout << "ID\tName\tDepartment\tAT\tDT\tWT\tTreatment time" << endl;
    patient p;
    for (int i = 0; i < size; i++)
    {
        p = pl[i];
        cout << p.patient_id << "\t" << p.name << "\t" << p.department << "\t\t" << p.arrival_time << "\t" << p.depart_time << "\t" << p.wait_time << "\t" << p.treatment_time << endl;
    }
    cout << "////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}

bool check_complete_all(struct patient pl[], int size)
{
    patient p;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        p = pl[i];
        if (p.remainder_time == 0)
        {
            count++;
        }
    }
    if (count == size)
    {
        return true;
    }
    return false;
}

bool check_complete(struct patient p)
{
    if (p.remainder_time == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int checkup(int pid, struct patient pl[], int num_patients, int current_time)
{
    for (int i = 0; i < num_patients; i++)
    {
        if (pl[i].patient_id == pid)
        {
            current_time += pl[i].treatment_time;
            pl[i].depart_time = current_time;
            pl[i].remainder_time = 0;
            pl[i].tat = current_time - pl[i].arrival_time;
            pl[i].wait_time = pl[i].tat - pl[i].treatment_time;
        }
    }
    return current_time;
}

int main()
{
    int num_patients;
    cout << "Enter Number of patients: ";
    cin >> num_patients;
    patient patient_list[num_patients];
    queue<patient> opd_list;
    vector<patient> emergency_list;

    for (int i = 0; i < num_patients; i++)
    {
        patient_list[i].patient_id = i + 1;
        cout << "Details of Patient " << patient_list[i].patient_id << endl;

        cout << "Enter the followings" << endl;
        cout << "Department(Emergency/OPD): ";
        cin >> patient_list[i].department;

        cout << "Patient's Name: ";
        cin >> patient_list[i].name;
        cout << "Arrival Time: ";
        cin >> patient_list[i].arrival_time;
        cout << "Treatment Time: ";
        cin >> patient_list[i].treatment_time;

        patient_list[i].remainder_time = patient_list[i].treatment_time;
        if (patient_list[i].department == "OPD")
        {
            // patient_list[i].level = 2;
            opd_list.push(patient_list[i]);
        }
        else
        {
            // patient_list[i].level = 1;
            cout << "Priority: ";
            cin >> patient_list[i].priority;
            emergency_list.push_back(patient_list[i]);
        }
    }
    int current_time = 0;

    while (!check_complete_all(patient_list, num_patients))
    {

        int pid = 0, pri = 20;
        // int selected=0;
        patient p;
        // for (int i=0; i<=emergency_list.size(); i++)
        // {
        //     p = emergency_list[i];
        //     if (p.remainder_time!=0 && p.arrival_time <= current_time && p.priority <= pri)
        //     {
        //         pid = p.patient_id;
        //         selected = i;
        //         cout<<"check0"<<endl;
        //     };
        //     cout<<"check1"<<endl;
        // };
        for (auto p : patient_list)
        {
            // cout<<"check1"<<endl;
            if (p.remainder_time != 0 && p.arrival_time <= current_time && p.priority < pri)
            {
                pid = p.patient_id;
                pri = p.priority;
            };
        };
        if (pid > 0)
        {
            current_time = checkup(pid, patient_list, num_patients, current_time);
        }
        else if (!opd_list.empty())
        {
            p = opd_list.front();
            if (p.arrival_time <= current_time)
            {
                pid = p.patient_id;

                current_time = checkup(pid, patient_list, num_patients, current_time);
                opd_list.pop();
            }
        }
        else
        {
            if (pid == 0)
                current_time++;
        }
        
        print_report(patient_list, num_patients);
        // sleep(2);
    }

    print_report(patient_list, num_patients);
}
