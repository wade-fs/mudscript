#include <room.h>

inherit ROOM;

void create()
{
        set("short", "聖火密室");
	set( "build", 256 );
        set("long", @LONG

	這兒是聖火教內部的密室, 這間密室應該是直接在石壁上
	挖掘建造的!!中間有一座岩臺, 上面擺有一座鼎(bottle)
	, 鼎內發出燦爛奪目的光華!!

LONG);

set("item_desc",([
"bottle": "  一座生鐵鑄成的獅頭鼎  "
]));
        set("exits", ([
            "east":__DIR__"2elder1"
        ]) );
setup();
}

void init()
{
 add_action("do_search","search");
 add_action("do_pull","pull");
}
 
int do_search(string str)
{
   object user;
   user=this_player();
   if( !user->query("quests/white-crystal",1))
   {
       write("這座鼎看來並沒有什麼奇怪的地方!!\n");
       return 1;
   }    

   if(str=="bottle")
   {
       write(" 你再仔細推敲一番, 發現獅耳(ear)的部分似乎有點古怪....\n");
       user->set_temp("have_search_bottle",1);
   }
   else if(str=="ear")
   {
       if(!user->query_temp("have_search_bottle",1))     
       write("哦!!原來是年久受潮, 生了鏽了!!\n");
       else
       {
           write("獅耳被你一碰之後, 鼎內的光華漸減, 你可以清楚地看見鼎內的事物 : 
     
           鼎內有六個洞, 其中一個洞是空的, 其餘則分別是...
     
      黑水晶(black-crystal)--渾天心法第六層心法之口訣
      藍水晶(blue-crystal)---渾天心法第七層心法之口訣
      黃水晶(yellow-crystal)-渾天心法第八層心法之口訣
      紅水晶(red-crystal)----渾天心法第九層心法之口訣
      綠水晶(green-crystal)--渾天心法第十層心法之口訣

      原來這裡就是渾天水晶的放置處!!你可以嘗試著拔起它們(pull)..\n");
      user->set_temp("can_pull",1);
       }   
   }
   else
       write("你在找什麼??\n");
    
  return 1;   
}      

int do_pull(string str)
{
 object user=this_player();
 object cry;

 if( (str=="black-crystal") && user->query("quests/white-crystal",1) )
 {
   if( user->query_skill("superforce",1) < 50 )
   {
   write("\n突然雙手感到一陣電噬...............哇!!!!黑水晶發出劇烈的強光....\n\n");
   return 0;
   }
   else
   {
   write("由於你已經練有基本心法, 黑水晶被你運勁一拔, 應聲而起!!\n",user);        
   cry=new("/open/prayer/obj/crystal2" );
   cry->move(user);
   return 1;
   }
}

 if(str=="blue-crystal") 
 {
   if( user->query_skill("superforce",1) < 85)
   {
   write("\n突然雙手感到一陣電噬...............哇!!!!藍水晶發出劇烈的強光....\n看來你的渾天心法等級還不夠.\n");
   return 0;
   }
   else
   {
   write("由於你已經練成第六層心法, 藍水晶被你運勁一拔, 應聲而起!!\n",user);        
   cry=new("/open/prayer/obj/crystal3" );
   cry->move(user);
   return 1;
   }
}     

 if(str=="yellow-crystal")
 {
   if( user->query_skill("superforce",1) < 120)
   {
   write("\n突然雙手感到一陣電噬...............哇!!!!黃水晶發出劇烈的強光....\n看來你的渾天心法等級還不夠.\n");
   return 0;
   }
   else
   {
   write("由於你已經練成第七層心法, 黃水晶被你運勁一拔, 應聲而起!!\n",user);        
   cry=new("/open/prayer/obj/crystal4" );
   cry->move(user);
   return 1;   
   }
}

 if(str=="red-crystal")
 {
   if( user->query_skill("superforce",1) < 160)
   {
   write("\n突然雙手感到一陣電噬...............哇!!!!紅水晶發出劇烈的強光....\n看來你的渾天心法等級還不夠.\n");
   return 0;
   }
   else
   {
   write("由於你已經練成第八層心法, 紅水晶被你運勁一拔, 應聲而起!!\n",user);        
   cry=new("/open/prayer/obj/crystal5" );
   cry->move(user);
   return 1;
   }
}

 if(str=="green-crystal")
 {
   if( user->query_skill("superforce",1) <200)
   {
   write("\n突然雙手感到一陣電噬...............哇!!!!綠水晶發出劇烈的強光....\n看來你的渾天心法等級還不夠.\n");
   return 0;
   }
   else
   {
   write("由於你已經練成第九層心法, 綠水晶被你運勁一拔, 應聲而起!!\n",user);        
   cry=new("/open/prayer/obj/crystal6" );
   cry->move(user);
   return 1;
   }
 }
}  
