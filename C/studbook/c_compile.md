

\section{Компиляция программы} \label{sec:compiling}
\subsection{Компиляция программы из одного файла}

Скомпилируем нижеприведённую программу (хранится в файле main.cpp) компилятором G++.

\begin{minted}[autogobble]{C++}
	#include <iostream>
	int main(){     
		std::cout << "Hello, World!\n";
		return 0;   }
\end{minted}

\marginpar{\RaggedRight во время работы в оболочке командной строки (например bash или PowerShell) будет полезны команды:\\ \mintinline{bash}{ls} -- показать файлы в текущей директории\\ \mintinline{bash}{cd <path_to_dir>} -- изменить текущую папку на указанную (можно указать полный абсолютный или относительный путь);\\ \mintinline{bash}{/.my_program_name} -- запустить программу из текущей папки}
\begin{minted}[autogobble]{bash}
	g++ main.cpp -o hello_world.exe
\end{minted}

После ключа {\tt -o} указывается имя исполняемого файла.

Полная поддержка стандартов языка С++ появляется в компиляторах часто спустя несколько месяцев или даже 1-2 года после публикации стандарта. Но отдельные, востребованные нововведения начинают поддерживаться относительно быстро. Иногда нововведения языка могут появится в компиляторе и раньше принятия стандарта, но это происходит редко. Однако по умолчанию компилятором используется не последний принятый стандарт, а более ранний. Для включения поддержки реализованных возможностей новых стандартов нужно отдельно указывать их название через параметр { \tt std}:
\begin{minted}[autogobble]{bash}
	g++ main.cpp -o hello_world.exe -std=C++20
\end{minted}

\subsection{Макросы препроцессора}

\href{https://en.cppreference.com/w/cpp/preprocessor/replace}{en.cppreference.com/w/cpp/preprocessor/replace}


\mintinline{C++}{__cplusplus} -- хранит имя используемого стандарта языка. Может принимать значения:  199711L,
201103L, 201402L, 201703L, 202002L или похожие, в зависимости от компилятора.

Макрос\index{макрос} \mintinline{C++}{__cplusplus} в MSVC:\index{MSVC}
\href{https://learn.microsoft.com/ru-ru/cpp/build/reference/zc-cplusplus?view=msvc-170}{learn.microsoft.com/ru-ru/cpp/build/reference/zc-cplusplus?view=msvc-170}



\subsection{Этапы компиляции} \label{sec:compile_stages}

\begin{enumerate}
	\item \textbf{Препроцессинг}\index{препроцессор}. Обработка директив \textit{препроцессора} C++: \mintinline{C++}{include} \mintinline{C++}{define}, \mintinline{C++}{ifdef}, и др. На этом этапе, в том числе, происходит вставка содержимого файлов указанных в директивах \mintinline{C++}{include} (рис. \ref{fig:cpp_cpp_h_compile}).
	\item Преобразование в Ассемблерный код.
	\item Преобразование в машинный код. В результате создаются \textit{объектные файлы} \index{файлы!объектные} из всех cpp фалов переданных компилятору. 
	\item \textbf{Компоновка}. Компоновщик (линкер)\index{линкер} \index{компоновщик} используя \textit{таблицу символов} объединяет объектные файлы и файлы статических библиотек в исполняемый файл. \\
	\emph{Таблица символов} --  это структура данных, создаваемая самим компилятором и хранящаяся в самих объектных файлах. Таблица символов хранит имена переменных, функций, классов, объектов и т.д., где каждому идентификатору (символу) соотносится его тип, область видимости. Также таблица символов хранит адреса ссылок на данные и процедуры в других объектных файлах.
	Именно с помощью таблицы символов и хранящихся в них ссылок линкер будет способен в дальнейшем построить связи между данными среди множества других объектных файлов и создать единый исполняемый файл из них.
	
	\begin{figure}
		\centering
		\includegraphics[width=1.2\linewidth]{img/cpp_intro/cpp_cpp_h_compile-Page-2.drawio.png}
		\caption{Этапы компиляции}
		\label{fig:enter-label}
	\end{figure}
\end{enumerate}
% Источник: https://habr.com/ru/post/478124/

Детальное описание процесса компиляции:\\
\href{https://en.cppreference.com/w/cpp/language/translation_phases}{en.cppreference.com/w/cpp/language/translation\_phases}


\subsection{Компиляция нескольких файлов и статической библиотеки}

Предположим, что исходный файл программы разбит на несколько файлов исходного кода:
\begin{itemize}[nosep, topsep=-8pt, after=\vspace{0.7ex}] 
	\item {\tt main.cpp} -- основной файл, содержит функцию main.
	\item {\tt my\_unit1.h}
	\item {\tt my\_unit1.cpp}
	\item {\tt my\_unit2.h}
	\item {\tt my\_unit2.cpp}
\end{itemize}



Компиляция: \mynobreakpar
\begin{minted}[autogobble]{bash}
	g++ main.cpp my_uni1.cpp my_unit2.cpp -o my_prog.exe
\end{minted}


Отметим, что имена заголовочных файлов не передаются компилятору потому, что их код будет вставлен препроцессором в те места, где из имена указаны в директивах {\tt include} (рис. \ref{fig:cpp_cpp_h_compile}).


Для ускорения программы компиляции отдельные cpp файлы можно скомпилировать заранее. Кроме того, исходный код таких файлов уже нельзя будет просмотреть. Эти файлы можно использовать как обычные cpp файлы при компиляции, их код статически (на этапе компиляции) будет включён в исполняемый файл.

todo: пример компиляции библиотеки

\href{https://github.com/VetrovSV/OOP/tree/master/examples/example_libs/simple_lib}{github.com/VetrovSV/OOP/tree/master/examples/example\_libs/simple\_lib}

todo: пример компиляции со статической библиотекой

Динамические библиотека -- это отдельный файл, который не включается в исполняемый файл во время компиляции, а может быть подключен программой в любое время её выполнения. Эти файлы имеют расширение dll в Windows.


\subsection{Параметры компиляции, настройки компиляции в IDE}
Некоторые параметры компилятора G++\marginpar{угловые скобки обозначают обязательные аргумент}
\begin{itemize}[topsep=0pt]
	\item \mintinline{bash}{--version} -- показать информацию о версии;
	\item \mintinline{bash}{-o <my_output_filename>} -- имя выходного (исполняемого) файла;
	\item \mintinline{bash}{-I <include path>} -- указывает путь к отдельной (дополнительной) папке с заголовочными файлами;
	\item \mintinline{bash}{-L <library path> } -- указывает путь к отдельной (дополнительной) папке со статическими библиотеками;
	\item \mintinline{bash}{-l <library> } -- указание необходимой статической библиотеки;
	\item \mintinline{bash}{-O1, O2, O3} -- оптимизации кода различного уровня, включая уменьшение размера файла; может замедлять компиляцию;
	\item \mintinline{bash}{--std=<standard_name>} -- указание стандарта языка: c++17, c++20 и др.
\end{itemize}


\textbf{Microsoft VisualStudio}

Чтобы получить доступ к страницам свойств, выберите >"Свойства проекта" в главном меню или щелкните правой кнопкой мыши узел проекта в Обозреватель решений и выберите "Свойства" (рис. \ref{fig:MSVC_Cpp_standartd})

\begin{figure}
	\includegraphics[width=1.1\linewidth]{img/cpp_intro/MSVC_Cpp_standartd.png}
	\caption{Окно свойств проекта Microsoft VisualStudio: настройка версии стандарта языка С++}
	\label{fig:MSVC_Cpp_standartd}
\end{figure}

см. также раздел \ref{sec:developer_tools} \nameref{sec:developer_tools}
