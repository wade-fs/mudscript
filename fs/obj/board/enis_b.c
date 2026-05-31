inherit BULLETIN_BOARD;
#include <ansi.h>
void create()

{
set_name(HIY"藍焰紫羽密藏寶盒"NOR,({"enis board","board"}));
set("location","/u/e/enis/workroom.c");
set("board_id","enis_b");
set("long",HIY"檀木外觀的一個小盒子,是藍焰紫羽打敗各大派高手後所得的寶物,\n之後此物便作為其與門下信眾溝通用的,\n如果不懂得用法,可以(help post)或是(help board).\n"NOR);
setup();
set("capacity",100);
set("master",({"enis"}));
}
