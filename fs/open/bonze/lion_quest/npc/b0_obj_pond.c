#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;
int do_temp(object);
//int dec_kee(object);
int do_set(object);
int do_delete_temp(object);
string ud;
object obj,room;
int utime,inf;

void create() {
	set_name("小池塘",({"pond"}));
//	set_name("湖泊",({"lake"}));
	set("long","在你眼前的低窪地區形成一個小池塘，也許\是有時候下的雨大了，或是地下有水脈所形成的。\n");
	set("飽和",100000);
	set("資源/液體", ([
		"種類": "水",
		"名稱": "清水",
		"剩": 100000,
		"止渴" : 30,
		"drink_func":0,
	]) );

        set("no_get",1);
        set("no_sac",1);
   setup();
        set("chat_chance",30);
        set("chat_msg",({

            HIC + "微風輕拂林間的枝葉，你感受到森林的幽靜～\n" + NOR,
      }));
        setup();
 }

void init()
{
	utime=uptime();
	obj = this_player();
	room = environment(this_object());
	ud = geteuid(obj);//改用euid，因為badman可以變換id

	if(!room->query("no_clean_up"))
	room->set("no_clean_up",1);

//  先mark這個比對時間，發現比對時間會造成某種錯誤，造成可以重覆呼叫mob
//	if(!room->query_temp("ud"))//沒有比對的時間，設定比對時間
//	{
//	room->set_temp("ud",utime);
//	}else{
//	  if( utime - room->query_temp("ud") >= 3600)//超過一小時，重設
//	  room->set_temp("ud",utime);
//	}

	if(interactive(obj))
	{
	  if(!room->query_temp(ud)) //如果沒有該玩家名字，叫mob
	  {
	  room->set_temp(ud,utime);//在房間設上玩家來過的記號，並呼叫mob
	  do_set(obj);
//	  dec_kee(obj); //因為是噴水池 所以 不需要扣血
	  }else{//已經有了，判斷是否大於一小時，大於一小時則重設並呼叫mob
	  if( utime - room->query_temp(ud) > 871 ) //本噴水池設定14分鐘31秒 by blazakira
	    {
	    room->set_temp(ud,utime);
	    do_set(obj);
//	    dec_kee(obj);
	    }
	  }
	}
}

//int dec_kee(object obj) //因為是噴水池 所以 不需要扣血
//{
//	obj = this_player();
//        obj->add("gin",-150);
//        obj->add("kee",-250);
//        obj->add("sen",-150);
//        return 1;
//}

int do_set(object obj) //本呼叫mob的item 需要在mob 身上設定刪除mob本身的配合程式 避免無限迴圈呼叫
{ //本區域已有限制最低exp始可進入 因此限制最高exp 冀望玩家參與其他區域的活動
        object mob;
        obj=this_player();
        if(obj->query_temp("quests/bonze/mob")== 1) return 1;  //設定【query_temp("quests/bonze/mob")== 1 】
		//為巡邏npc的判斷 以避免觸發本區mob無意義的呼叫 且可避免本npc離開本區域

		if(obj->query("max_force") > 8000 && //設定超過exp1000 以及 maxforce 超過8000 以上的玩家
           obj->query("combat_exp") > 10000000) return 1; //不能使用本物件來呼叫mob 故為限制本區mob數量 
        switch(random(11)+1) //需依照物件總數作調整
        {
           case 1  : mob=new(__DIR__"b9_marksman_shooting.c");
                     mob->move(environment(obj));
                     break;
           case 2  : mob=new(__DIR__"b9_doctor_guard.c");
                     mob->move(environment(obj));
                     break;
           case 3  : mob=new(__DIR__"b9_tendo_monk.c");
                     mob->move(environment(obj));
                     break;
           case 4  : mob=new(__DIR__"b9_swordman_disciple.c");
                     mob->move(environment(obj));
                     break;
           case 5  : mob=new(__DIR__"b9_dancer_violet.c");
                     mob->move(environment(obj));
                     break;
           case 6  : mob=new(__DIR__"b9_duan_savant.c");
                     mob->move(environment(obj));
                     break;
           case 7  : mob=new(__DIR__"b9_fighter.c");
                     mob->move(environment(obj));
                     break;
           case 8  : mob=new(__DIR__"b9_gblade_blademan.c");
                     mob->move(environment(obj));
                     break;
           case 9  : mob=new(__DIR__"b9_poison_guard.c");
                     mob->move(environment(obj));
                     break;
           case 10  : mob=new(__DIR__"b9_scholar_bookman.c");
                     mob->move(environment(obj));
                     break;
           case 11  : mob=new(__DIR__"b9_snow_warrior.c");
                     mob->move(environment(obj));
                     break;
           default : break;
        }

        return 1;
}
