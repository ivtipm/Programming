# Устройство памяти программы

\begin{itemize}
	\item Статическая память (data на рис.). Хранит глобальные переменные.
	\item Динамическая память (heap, куча).\index{куча}\index{heap} Память, которая выделена оператором \mintinline{C++}{new}.
	\item Автоматическая паять (stack, стек)\index{стек!область памяти}\index{stack!memory}\marginpar{\raggedright не стоит путать область памяти \textit{стек}, с одноимённым типом данных и стеком процессора}. Хранит адреса возврата функций, локальные переменные, параметры функций.
	\item Сегмент кода (text на рис.)
\end{itemize}

\begin{figure}[h]
	\centering
	\includegraphics[width=0.35\linewidth]{img/cpp_intro/program_memory.png}
	\caption{Устройство памяти программы}
	\label{fig:program_memory}
\end{figure}


Использование оператора \mintinline{C++}{new} внутри функции приводит к выделению памяти в куче. Но стоит дополнительно позаботится, чтобы не потерять указатель на эту память, который может быть локальной переменной.

\begin{minted}[autogobble]{C++}
	void foo(){
		int * arr = new int [1024];
		// arr - указатель, локальная переменная находится в стеке.
		// 1024 элемента массива располагаются в куче
		
		// doing staff ....
	}
\end{minted}

После завершения функции foo исчезнет переменная arr. Уже будет нельзя ни освободить эту память, ни обратиться к ней то есть произойдёт утечка памяти\index{память!утечка}. Можно решить проблему вернув адрес указателя:

\begin{minted}[autogobble]{C++}
	int* foo(){
		int * arr = new int [1024];
		
		// doing staff ...
		
		return arr;
	}
	
	
	int * array = foo();
	
	// ...
	
	delete[] array;
\end{minted}


\textbf{access violation}, \textbf{segmentation fault}\index{access violation}\index{segmentation fault} -- 

\textbf{Стек вызовов}\index{стек!вызовов} (call stack)\index{stack!call} -- ...
