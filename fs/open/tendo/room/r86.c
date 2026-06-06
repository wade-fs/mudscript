// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","新膜拜堂");
        set("long", @LONG
這兒是天道派的禁地，除了掌門人外其他的門人皆不得進入此地
。你最好趕緊離開這，否則掌門人回來時若看見你在這那你就完了。
你蒼促的環視了一下四周，發現這兒十分乾淨，幾乎是一塵不染，四
周擺了許許多多的書，你走近瞧了一下，發現上面寫著「天道派之武
學密笈」、「天道派之仙術密笈」、....。這些東西令你不想離開這
，但又怕當你在翻閱書輯時掌門人會突然回來，於是只得放棄了..。
LONG);
  set("light_up",1);
set("exits", ([
        "north":__DIR__"r61",
]));
  setup();
}
