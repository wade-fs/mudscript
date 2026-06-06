// by roger && taifar
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short","迴翡小逕");
set ("long", @LONG
淒沚清流一帶，勢若遊龍，兩邊石欄上皆係水晶玻璃各色風燈，點
如銀光雪亮，上面楓槐諸樹，雖無花葉卻用各色綢綾紙絹及通草為
花，更兼池中荷荇上下爭輝水天彩煥。牡丹爛麗，白芋漂潔，新綠
漲添，盈盈汀霈。
LONG);



  set("exits", ([
            "north" : __DIR__"77",
            "west"  : __DIR__"55",
                ]));

        setup();
}
