inherit BULLETIN_BOARD;
#include <ansi.h>
void create()

{
set_name(HIR + "kalin麻辣辛酸版" + NOR,({"kalin board","board"}));
set("location","/u/k/kalin/workroom.c");
set("board_id","kalin_b");
set("long",HIY + "為上古時代的水晶,小池在一偶然的機緣下發現的,\n而後便作為巫師群傳遞或留言的水晶版,\n如果不懂得用法,可以(help post)或是(help board).\n" + NOR);
setup();
set("capacity",100);
set("master",({"kalin"}));
}

