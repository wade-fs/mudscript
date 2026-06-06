inherit ROOM;
#include <ansi.h>
void create ()
{
set("short",YEL"雙冥祭台"NOR);
set("long",@LONG
這是掌管著【生】【死】雙冥王的祭台, 左邊司【生】
, 右邊管【死】, 傳聞當生死兩祭台開啟時, 即是死靈骨魔
復活之時...
    中央放置一個骨魔的雕像(statue)
LONG);
set("no_light",1);
set("exits",([
"up":__DIR__"g-r01",
"north":__DIR__"g-s09",
"east":__DIR__"g-s02",
"west":__DIR__"g-s03",
]));
set("item_desc",([
"statue":"一個死靈骨魔的雕像, 感覺上似乎有點怪異!!\n",
]));
set("no_transmit",1);
setup();
}

void init()
{
        add_action("search_statue", "search");
}

int search_statue(string str)
 {
 object butterfly;
 butterfly=present("life-death-butterfly",this_player());
 if (str!="statue" ) return 0;
      if (!butterfly ) {
      return 0;
           } else

{ 
        message_vision("$N發覺雕像的右眼似乎有點詭異，就在此時生死蝶在$N懷中不安分了起來。\n",this_player());

        destruct(present("life-death-butterfly",this_player()));
        call_out("do_a",1,this_player());
        return 1;
}
}
int do_a(object ob)
{ 
 this_player()->set_temp("ghost-quest/cankill-king",1);
 message_vision(HIG"\n生死蝶從$N的懷你掙扎出來，朝著雕像的右眼飛了過去。\n"NOR,this_player());
 call_out("do_b",1,this_player());
}
int do_b(object ob)
{  
 message_vision(HIY"\n$N臨機一動，大步的追向生死蝶。\n\n"NOR,this_player());
 this_player()->move("/open/ghost-hole/g-s04.c");
 call_out("do_c",2,this_player());
}
int do_c(object ob)
{  
 message_vision(HIM"\n(我追，我追，我追追追。)\n"NOR,this_player()); 
 call_out("do_d",2,this_player());}
int do_d(object ob)
{  
 message_vision(HIM"\n(我追，我追，我追追追。)\n"NOR,this_player()); 
 call_out("do_e",2,this_player());
}
int do_e(object ob)
{  
 message_vision(HIW"\n($N開始也點喘，額頭上也滲出一顆顆斗大的汗珠。)\n"NOR,this_player()); 
 call_out("do_f",2,this_player());
}
int do_f(object ob)
{  
 message_vision(HIW"\n($N跑的氣喘吁吁，汗流浹背。)\n"NOR,this_player()); 
 call_out("do_g",2,this_player());
}
int do_g(object ob)
{  
 message_vision(HIW"\n($N雙腿發軟，眼冒金星，但還是咬緊牙關，死命的追的生死蝶)。\n"NOR,this_player()); 
 call_out("do_h",2,this_player());
}
int do_h(object ob)
{  
 message_vision(BLU"\n正當生死蝶與$N僅有一步之隔時，生死蝶突然飛進了一個洞穴中。\n\n"NOR,this_player()); 
 this_player()->move("/open/ghost-hole/g-s05.c");
}



