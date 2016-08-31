# 2015 Kookmin University UROP Project

In this project, our team detects well known vulnerable part of OpenSSL which calls ‘Heartbleed bug’ in binary level. We used objdump for disassembled binary code to assembly. The vulnerable code can be figured out on the binary level when inserting branch statement or user functions at top and bottom of it in the high-level language before disassembled. That high-level code translated to branch or function call instructions as the same place in the entire code. After extract vulnerable part, we compared this assembly opcode patterns to the other programs which have Heartbleed bug. N-gram method and Jaccard similarity are used for analyzing it

----------

Faculty Mentor : Prof.Myungkeun Yoon

Author : Yunho Kim, Sunghyun Hong

* TimeLine

  3rd week of Sep. : Extract binary and assembly code from execute file

  1st week of Oct. : Found vulnerable code in assembly code
  
  2nd week of Oct. : Write the script code for vulnerable code detection
  
  1st week of Nov. : Find some difference of assembly code when compiled with optimize option
  
  3rd week of Nov. : Study jaccard index for measure similarity between origin source and vulnerable code 
  
  1st week of Dec. : Write the script code for measure similarity between origin source and vulnerable code (./jaccard/SimilarityCheck.cpp)
 
