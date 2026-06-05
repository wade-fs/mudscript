inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
set_name(HIC + "琥珀水晶石" + NOR,({"board"}));
set("location","/open/clan/god/hall");
set("board_id","chan");
set("long","這是用來顯示布衣行蹤的水晶石，若找布衣有事也可以記錄在上面\n");
setup();
set("capacity",50);
replace_program(BULLETIN_BOARD);
}
