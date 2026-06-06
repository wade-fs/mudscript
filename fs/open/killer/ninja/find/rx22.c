// open/killer/ninja/find/rx21.c
// 當玩家發生抉擇錯誤，就會受到嚴重精神傷害，退回最初點
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "心靈探索");
  set ("long", @LONG
  
  你覺得你還是小心一點，不要插手以免干擾到存在的歷史
  所以你決定繼續觀戰，但是沒想到老祖忽然發出一記
  威力強大的難以想像的魔氣殺，配合霸雨式手法，
  也就是更上一層樓的『霸雨.魔氣殺』，貫足在暗器之上
  但是目標並非那個人，反而朝著自己所在的這一群仙劍門徒而來!
  逼得那個人放棄攻擊老祖，反身設法擊落這一些暗器!
  但是多如繁星，且貫足魔氣的暗器，怎麼可能全部攔的下來
  許多仙劍弟子分分中招，很不幸的你也是其中一個........
  
   
LONG);
  set("no_transmit",2);
  setup();
}

void init()
{
    object ob=this_player();
    if( interactive(ob))
	    remove_call_out("greeting");
  call_out("greeting",3 , ob);   
}

void greeting(object ob)
{
   if( ob->query_temp("firstpart")== 8)    
   {
     ob->set_temp("firstpart",7);
     ob->set("sen",1);
     ob->set("gin",1);
     tell_object(ob," 你感到精神逐漸渙散....逐漸陷入昏迷狀態..... \n");
     ob->move("/open/killer/room/pillrm.c");
    }
    // 基本上是很不合理啦，就當成巫師測試用，一到最初點
    else 
     ob->move(__DIR__"r1.c");
}

