inherit BULLETIN_BOARD;
#include <ansi.h>
void create()

{
set_name(HIR"KKyeo的 隨手貼"NOR,({"kkyeo board","board"}));
set("location","/u/k/kkyeo/workroom.c");
set("board_id","kkyeo_b");
set("long",HIY"這是kkyeo發明的先進產物,\n作為巫師群傳遞或留言還是他的IDEA的隨手貼,\n如果不懂得用法,可以(help post)或是(help board).\n"NOR);
setup();
set("capacity",100);
set("master",({"kkyeo"}));
}
