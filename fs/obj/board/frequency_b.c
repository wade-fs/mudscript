inherit BULLETIN_BOARD;
#include <ansi.h>
void create()

{
set_name(HIY"高頻濾波器"NOR,({"frequency board","board"}));
set("location","/u/f/frequency/workroom.c");
set("board_id","frequency_b");
set("long",HIW"淨化世間雜訊的先進通訊產品，能確保訊息無失真傳達。"NOR);
setup();
set("capacity",100);
set("master",({"frequency"}));
}

