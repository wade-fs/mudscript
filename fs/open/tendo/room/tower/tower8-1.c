
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","密室");
        set("long", @LONG
這是一個空曠、乾淨、擺設十分簡單，只有一張床和一些簡單家
俱的房間，不過你注意到，東邊的牆(wall)和別的地方的牆顏色有點
不同，你在想--可能是因為地道的關係吧!!且左右的火把閃爍不定使
你更加確定你的推測。
LONG);
set("item_desc", ([ /* sizeof() == 1 */
"wall" : "你發現這個牆怪怪的，似乎可以推動。
",
]));

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"tower8.c",
]));
  set("no_transmit",1);
  setup();
}
void init()
{
        add_action("do_push","push");
}

int do_push(string str)
{
        object who;
        who = this_player();

        if(str!="wall"){return 0;}
        tell_object(who,"你輕輕的推了一下牆，但牆卻快速的轉了一圈，也連帶把你轉"+"了進去。\n");
        who->move("/open/tendo/room/tower/tower8-2");
        tell_room(this_object(),"你看到盡頭的牆被"+who->query("name")+"一推之下"
				+"轉動了一圈，而"+who->query("name")+"也被牆給"+
				"轉了進去。\n");
        return 1;
}


