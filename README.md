# CppThreadPool

This repository is home to a Thread Pool project written in C++.

# Purpose and Intent

With the mass popularization and increased utilization of multi-core processors, serial programming is going to be forced to resign in favor of parallel and concurrent programming. I believe thread pools are an introduction into that parallel computing paradigm, and with that also believe that thread pools bring a significant advantage to the table in terms of high performance computing.

# Inspiration

The heart of this project is inspired by a desire to squeeze every last bit of computing horsepower in order to make the most out of any hardware available. Stemming from that concept, jobification and task based program architecture is highly intriguing, and I believe will be imperative that any programmer of this century should be well versed in. As mentioned previously, the current hardware platform is increasingly parallel, and serial programming will soon become the Achille's Heel of any modern compute platform.

# Plans and Goals

I intend to develop a working, thread-safe, thread pool, which is able to create, populate, and distribute jobs among threads to be completed in a generic way. That is to say this implementation will for all intents and purposes be developed in a manner that will promote platform and machine independence. In a world of proprietary software, the only way to move forward is with unification and open source. As a programmer it's my responsibilty to promote the paradigms I believe in, and will to the best of my abilities serve to further those movements.

# Reason for using github

I am making use of github's distributed development service as a backup to my local files, as well as utilizing the cloud for development across machines for convenience to the developer(myself). Also, should I decide to invite other developers into the project, github is the most popular version control system as of 2017.

# Possible use-cases

A thread pool should be highly scalable and efficient in order to promote the utmost performance in any execution environment. With that in mind, the implementation found in this repository will be geared towards those processes that require "horsepower" to compute real-time data and simulations. My primary focus is the application of multi-threading and jobification to the video game creation environment. I am also interested in any kind of scientific application such as real-time simulations of natural mechanics, those being fluids, thermo and aerodynamics, etc,.

# Terminology

In this environment, on this specific project, which is headed by a currently uninformed dreamer of a programmer, some terminology will be utilized (possibly incorrectly) to describe the project and it's goals. Most notably "thread pool", in this context will be used to describe a data structure filled with thread objects, who will remain in a constant idle state waiting for jobs to be fed to them. "Threads" are objects that handle the execution of jobs or tasks in a parallel way. "Jobs" and "tasks" will be used semi-interchangeably where jobs are individual programs or "scripts" that can be executed rather simply by a thread, and tasks are a larger compilation of jobs or a more complex execution query. "Parallel" and "multi-threaded" are more than likely going to be used incorrectly as I'm currently still unsure of the differences.

