**date:17th july**

Duration: 50 min

goal: Read and understand the Web Crawler Student Handbook before starting the design proposal.

problem :
The handbook introduced several new project requirements beyond implementation, including design proposal expectations, architecture review, benchmarking, distributed crawler design, and future compatibility with the Indexer. Understanding how these phases fit together before coding was initially confusing.

What I Tried:
Read the handbook section by section and noted the project workflow, required components, evaluation criteria, design proposal requirements, testing expectations, and future phases. I also focused on understanding how the crawler output will be consumed by the Indexer in the next project and why the architecture must be designed with future compatibility in mind.

Outcome:
Completed the handbook and gained a clear understanding of the complete project lifecycle, required deliverables, architecture expectations, component responsibilities, testing and benchmarking requirements, and how the Web Crawler fits into the larger Search Engine pipeline.

**date:17th july**

Duration: 50 min

Goal:Update the HashMap design proposal to match the final implementation made using dynamic array and linked list.

Problem:
I realized that my design proposal was outdated because it described an implementation using raw bucket arrays, whereas the final implementation had been refactored to use my own DynamicArray and LinkedList classes.

What I Tried:
Reviewed the existing design proposal and updated the internal representation, component interactions, memory diagrams, and implementation details to accurately reflect the final architecture where DynamicArray is used for bucket storage and LinkedList is used for separate chaining.

Outcome:
Successfully cleaned the repository by synchronizing the design proposal with the final codebase. The documentation now accurately represents the implementation, making it consistent and easier to understand during evaluation.


**date:17th july**

Duration: 2 hour

Goal: Research the core components of the Web Crawler like frontier,seen url store ,page storage and url normalizer along with their complexities and what data structures would be appropriate for this.

Problem:
The crawler consists of multiple independent components—Frontier, Seen URL Store, and Page Storage—and each can be implemented using different data structures. I needed to understand the responsibility of each component, their interactions, and justify the most suitable implementation instead of selecting data structures arbitrarily.

What I Tried:
Researched the working principles of the Frontier, Seen URL Store, and Page Storage by studying crawler architecture and documentation. Compared different implementation approaches for each component, analyzed their time complexity and memory requirements, and evaluated how my previously implemented DynamicArray, LinkedList, and HashMap could be reused effectively. This helped me understand the trade-offs involved in choosing data structures for efficient URL management, duplicate detection, and page storage.

Outcome:
Developed a clear understanding of the purpose, responsibilities, and interactions of the Frontier, Seen URL Store, and Page Storage components. The research provided the foundation for making informed design decisions and preparing an implementation that is scalable, modular, and compatible with the later Indexer component.


