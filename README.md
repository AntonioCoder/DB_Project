# DB_Project
Lecture foundation management system.

This system allows to provide the controled access to auditories and equipment of HEE.
It's devided on subsystems:

- Base (Igor-Sergieiev, tomodachijanai)
    This partition controls all low level proc. as soon as the client-server logic. Response for providing controlled access and general messaging of entire system. 

- DataBase (Gemofort) // CRITICAL //
    Response for storing in appropriate way, processing and managin information, involves database topology, search-manage logic and database API.

- GUI (AntonioCoder)
    It incorporates all HUD and GUI for the whole system. Devided on different platforms.

- Logging (MazanYan) // CRITICAL //
    Provides logging of results, enter/exit, emergency situations and so on.

There are folders for each subsystem. Generalisation level locates in the root of the file system.

@author RingaVirda
