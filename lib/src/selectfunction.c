#include <stdio.h>
#include "header.h"

void select_function(int argc, char *argv[]){
    (void)argc;
    (void)argv;
#if MODULE == 1 && TASK == 1
        print_helloworld();

#elif MODULE == 1 && TASK == 2
        print_c_helloworld();

#elif MODULE == 1 && TASK == 3
        fahr_to_cels_table_0to300();

#elif MODULE == 1 && TASK == 4
        cels_to_fahr_user_input();

#elif MODULE == 1 && TASK == 5
        Celsius_to_Fahrenheit_table_300_to_0();

#elif MODULE == 1 && TASK == 6
        expression_of_EOF();

#elif MODULE == 1 && TASK == 7
        value_of_EOF();

#elif MODULE == 1 && TASK == 8
        count_bl_t_nl();

#elif MODULE == 1 && TASK == 9
        remove_blanks_by_one();

#elif MODULE == 1 && TASK == 10
        replace_blankspace_t_n_b();

#elif MODULE == 1 && TASK == 11
        word_count();

#elif MODULE == 1 && TASK == 12
        one_word_per_line();

#elif MODULE == 1 && TASK == 13
        print_a_histogram();

#elif MODULE == 1 && TASK == 14
        print_histogram_lengths_words();

#elif MODULE == 1 && TASK == 15
        celsius_to_fahr_function();

#elif MODULE == 1 && TASK == 16
        longest_line();

#elif MODULE == 1 && TASK == 17
        longer_than_8_characters();

#elif MODULE == 1 && TASK == 18
        remove_trailing_blanks_and_tabs();

#elif MODULE == 1 && TASK == 19
	reverses_the_character_string_s();

#elif MODULE == 1 && TASK == 20
        detab();

#elif MODULE == 1 && TASK == 21
        entab();

#elif MODULE == 1 && TASK == 22
        fold();

#elif MODULE == 1 && TASK == 23
        remove_comments();

#elif MODULE == 1 && TASK == 24
	rudimentary_syntax_errors();

#elif MODULE == 2 && TASK == 1
	range_of_datatype();

#elif MODULE == 2 && TASK == 2
	loop_equivalent_to_for_loop();

#elif MODULE == 2 && TASK == 3
	htoi();

#elif MODULE == 2 && TASK == 4
	squeeze();

#elif MODULE == 2 && TASK == 5
	any();

#elif MODULE == 2 && TASK == 6
	setbits();

#elif MODULE == 2 && TASK == 7
	invert();

#elif MODULE == 2 && TASK == 8
	rightrot();

#elif MODULE == 2 && TASK == 9
	setbits();

#elif MODULE == 2 && TASK == 10
	upper_to_lower();

#elif MODULE == 3 && TASK == 1
	binary_search();

#elif MODULE == 3 && TASK == 2
	escape();

#elif MODULE == 3 && TASK == 3
	expands();

#elif MODULE == 3 && TASK == 4
	itoa();

#elif MODULE == 3 && TASK == 5
	itob();

#elif MODULE == 3 && TASK == 6
	itoa_with_padding();

#elif MODULE == 4 && TASK == 1
	strindex();

#elif MODULE == 4 && TASK == 2
	atofloat();

#elif MODULE == 4 && TASK == 3
	reverse_polish_notation();

#elif MODULE == 4 && TASK == 4
	print_swap_clear_stack();

#elif MODULE == 4 && TASK == 5
	sin_exp_pow_stack();

#elif MODULE == 4 && TASK == 6
	handling_variable();

#elif MODULE == 4 && TASK == 7
	push_back_entire_string();

#elif MODULE == 4 && TASK == 8
	Modify_getch_ungetch();

#elif MODULE == 4 && TASK == 9
	push_back_string_Eof_handling();

#elif MODULE == 4 && TASK == 10
	rpn_getline();

#elif MODULE == 4 && TASK == 11
	modified_getop_wo_un_getch();

#elif MODULE == 4 && TASK == 12
	itoa_recursion();

#elif MODULE == 4 && TASK == 13
	reverse_string_recursion();

#elif MODULE == 4 && TASK == 14
	macro_swap();

#elif MODULE == 5 && TASK == 1
	change_getint();

#elif MODULE == 5 && TASK == 2
	getfloat();

#elif MODULE == 5 && TASK == 3
	stringcat();

#elif MODULE == 5 && TASK == 4
	substringatend();

#elif MODULE == 5 && TASK == 5
	str_functions();

#elif MODULE == 5 && TASK == 6
	my_function();

#elif MODULE == 5 && TASK == 7
	sort_lines();

#elif MODULE == 5 && TASK == 8
	calender();

#elif MODULE == 5 && TASK == 9
	calender_pointer();

#elif MODULE == 5 && TASK == 10
	rpn_cl(argc, argv);

#elif MODULE == 5 && TASK == 11
	entab_detab_cl(argc, argv);

#elif MODULE == 5 && TASK == 12
	entab_detab_shorthand(argc, argv);

#elif MODULE == 5 && TASK == 13
	tail_lines(argc, argv);

#elif MODULE == 5 && TASK == 14
	sorting_in_reverse(argc, argv);

#elif MODULE == 5 && TASK == 15
	string_fold(argc, argv);

#elif MODULE == 5 && TASK == 16
	string_dir_fold(argc,argv);

#elif MODULE == 5 && TASK == 17
	sorting_field(argc, argv);

#elif MODULE == 5 && TASK == 18
	direct_dcl();

#elif MODULE == 5 && TASK == 19
	undeclare();

#elif MODULE == 5 && TASK == 20
	dcl_argument();

#elif MODULE == 6 && TASK == 1
	get_word();

#elif MODULE == 6 && TASK == 2
	variable_names( argc, argv);

#elif MODULE == 6 && TASK == 3
	cross_reff();

#elif MODULE == 6 && TASK == 4
	cross_reff_dec_order();

#elif MODULE == 6 && TASK == 5
	un_def();

#elif MODULE == 6 && TASK == 6
	pre_processor();

#elif MODULE == 7 && TASK == 1
	upper_lower(argc, argv);

#elif MODULE == 7 && TASK == 2
	print_non_graphic_characters();

#elif MODULE == 7 && TASK == 3
	min_printf();

#elif MODULE == 7 && TASK == 4
	min_scanf();

#elif MODULE == 7 && TASK == 5
	rpn_sscanf();

#elif MODULE == 7 && TASK == 6
	file_compare(argc,argv);

#elif MODULE == 7 && TASK == 7
	find_keyword(argc,argv);

#elif MODULE == 7 && TASK == 8
	print_files(argc,argv);

#else
        printf("Invalid module/task selection\n");
#endif
}
