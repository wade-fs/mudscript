// Room: /u/o/onion/workroom.c~
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "洋蔥的小窩");
	set("long", @LONG
	
	一個小小的房間,隨意的堆著一些東西,你最感到興趣的是房間角落放著
	一張大桌子,上面擺著各式各樣的書(book),另外你還聞到了一陣陣的香
	味從窗邊傳來,仔細一看卻赫然發現一盆【天山雪蔥】(onions),白色的
	花瓣傳來撲鼻的香味..
	
LONG
	);

	set ("item_desc", 
	(["book" : "
	你看到這些厚厚的書包括了電子學,工數,線控..等密密麻麻的原文書,不
	禁由衷的佩服起[Onion]來了...\n",
          "onions" : "
        神祕的至寶,傳聞中的仙物--【天山雪蔥】,竟然在這出現了,透體白如玉
        有如雪般,因微風還輕輕的顫抖著,清淡的香味使你忍不住想要好好的品嗅
        (sniff)一番...\n"]));
      
        set("objects", ([
        "/u/o/onion/npc/noname": 1,
//      "/u/o/onion/npc/vendor": 1,
	 ]));	
        set("exits", ([ 
		"up" : "/open/ping/room/p1",
		"down" : __DIR__"fightroom",
		"north" : "/open/capital/room/SCH",
        	"west" : "/open/biau/room0",
		"south" : "/open/capital/room/D03",

        	"east" : "/open/wiz/hall1",
         ]));
        set("no_clean_up", 0);
        set("valid_startroom", 1);
                             
        setup();
                  }                                    
                                                              	 
	void init()
	{
	 add_action("do_sniff","sniff");
	}
	int do_sniff(string str)
	{
                object me = this_player();
                int max;
                
                    write("你走上前去, 用力的吸了一大口氣,哇...口氣清新... \n"
                    +"吸入的香氣在你身體的奇經八脈之內竄動,你感到一切狀況都復原了...\n");
		    me->reincarnate();
		    max = me->query("max_s_kee");
		    me->set("s_kee",max);		
                    max = me->query("max_gin");
                    me->set("eff_gin",max);
                    me->set("gin",max);
                    max = me->query("max_kee");
                    me->set("eff_kee",max);
                    me->set("kee",max);
                    max = me->query("max_sen");
                    me->set("eff_sen",max);
                    me->set("sen",max);
		    max = me->query("max_force");
		    me->set("force",max);
		    max = me->query("max_mana");
		    me->set("mana",max);	
                    max = me->max_food_capacity();
                    me->set("food",max);
                    max = me->max_water_capacity();
                    me->set("water",max);
                    me->clear_condition();
                     
                    tell_room(environment(me),(string)me->query("name")+
                    "走近【天山雪蔥】,聞了一聞,臉上露出幸福的笑容.\n",({this_object(), me}));
                    return 1;
        }
