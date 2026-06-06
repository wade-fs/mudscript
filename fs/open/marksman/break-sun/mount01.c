// by Alucard 2009/09
inherit ROOM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
void create () {
        set("short","山腳下");
		set("long", "往前望去一是座高山，總覺得爬上頂峰是個遙不可及的願望，每
往上踏一步都是一種考驗，仰起頭看見的是十顆熾熱的太陽，光是用
看的就已經受不了了，更何況是處在如此炎熱的地方，但是為了找人
，也得硬著頭皮上了。
" );
        set("no_auc", 1);
        set("no_transmit", 1);
		set("no_scale",1);
		set("no_chome",1);
        set("light_up",-1);
		set("outdoors", "/open/main");
        set("exits", ([
            "up" :  __DIR__"mount02",
			"south" :  __DIR__"street05",   
      ]));
        setup();
}
