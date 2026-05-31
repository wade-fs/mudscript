inherit BULLETIN_BOARD;
#include <ansi.h>
void create()

{
set_name(HIY"臨時記錄板"NOR,({"temp board","board"}));
set("location","/u/r/raccoon/workroom.c");
set("board_id","raccoon_b");
set("long",HIW"淨化世間雜訊的先進通訊產品，能確保訊息無失真傳達。"NOR);
setup();
set("capacity",100);
}

