// by Alucard 2009/09
inherit ROOM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
void create () {
        set("short","枯\木林入口");
		set("long", "往北走是一望無際的白色樹海，雖說是樹海，但其實都是枯\枝，這是
由於長期受到烈陽照射而造成的，據說裡面單調的景色，往往使人迷途
而不自知，最後身陷樹海，再也走不出來，路旁有一塊牌子(mark)......
" );
        set("no_auc", 1);
        set("no_transmit", 1);
		set("no_scale",1);
		set("no_chome",1);
        set("light_up",-1);
		set("outdoors", "/open/main");
        set("exits", ([
            "north" :  __DIR__"maze",
			"enter" :  __DIR__"transmit-old",   
      ]));
	    set("item_desc", ([
        "mark" : "據說，從前有3個人想前往一邪惡的島嶼，為世間降妖除魔，但因為人力不足，
所以經由一連串神秘方位的指引，而增為30人，最後順利完成任務。
",]));
        setup();
}
