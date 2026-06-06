//暗之神殿 by frequency
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "焰靈燃之間");
  set ("long", @LONG
這裡是炎之神殿的主廳，無止盡燃燒的熊熊火舌，彷彿要吞噬所
有物質般四處飛竄。在烈火燃燒最緻盛的中心地帶，似乎可看到一團
模糊且特別光亮的的白焰(flame)，那就是傳說中祝融之魂的棲息地。
LONG);

  set("exits", ([
  "up" : __DIR__"fmount3.c",
               ]));
  set("no_fight",1);
  set("valid_startroom",1);
  set("no_transmit",1);
  set("hall",1);
  set("item_desc", ([ 
  "flame" : "永不熄滅的烈火，令人無法接近。\n",
                     ]));
  set("search_desc", ([ 
  "flame" : "太過接近將會遭受三昧真火焚身的痛苦喔(burn)，還是懷著虔誠的心膜拜一下好了(pray)。\n",
                      ]));

  setup();
}

void init()
{
        add_action("do_pray","pray");
        add_action("do_burn","burn");
	add_action("do_blend","blend");
}

int do_pray(string str)
{
  object me = this_player();
  string att =  me->query("attribute");
  if(att != "fire" && (!str || str != "flame"))
   {
          write("突然間白光四射，接著從四面八方包圍著你，轉眼間你已被烈火吞噬。\n");
          me->unconcious();
          me->set("force",1);
          me->set("atman",1);
          me->set("mana",1);
          me->set("force_factor",0);
   }else{ 
         if(str)
         {
           if(str == "flame")
           {
            if(present("fire-spirit",me))
             {
              write("你身上的祝融炎之魂突然化作ㄧ道火焰，迅速向四周瘋狂延燒。\n");
              write("炎之魂似乎期待著和你兵器的融合(blend fire)\n");
             }else write("ㄧ陣惱怒的聲音由白焰中傳來：『你身上沒有我想要的東西。』\n");
           }else{
                if(att == "fire")   write("啊你是在拜什麼東西啊!?\n");
                }
         }else{
                if(!me->query_temp("pray_fire"))
                 {
                   write("突然間，烈芒瘋狂的注入你體內，源源不絕的陽炎火勁令你戰意高昂。\n");
                   me->add_temp("apply/damage",5);
                   me->add_temp("apply/attack",5);
                   me->add_temp("apply/parry",-5);
                   me->add_temp("apply/dodge",-5);
                   call_out("remove_fire",120,me); 
                   me->set_temp("pray_fire",1);
                 }else write("你只覺得眼前的白焰令人肅然起敬。\n");
              }
       }
       return 1;
}

int remove_fire(object me)
{
   me = this_player();
   remove_call_out("remove_fire");
   write("你身上的火勁漸趨稀薄，最後終於消失了。\n");
     me->add_temp("apply/damage",-5);
     me->add_temp("apply/attack",-5);
     me->add_temp("apply/parry",5);
     me->add_temp("apply/dodge",5);
     me->delete_temp("pray_fire");
}

int do_burn()
{
  object me = this_player();
  if(me->query("attribute") == "fire")
  {
  	message_vision(HIR + "一道烈火包圍了$N，接著突然消失無蹤。\n" + NOR,me);
  	me->move("/open/common/room/inn");
  	message_vision(HIR + "一道火光突地竄起，待得烈焰燃盡，$N的身形逐漸浮現。\n" + NOR,me);
  }else{
        write("這邊實在好熱呀。\n");
        me->add("water",-10);
        }
  return 1;
}

int do_blend(string str)
{
	object me,ob,ob1,ob2;
	me=this_player();
	ob=this_object();
	ob1=present("fire-spirit",me);
	ob2=present("fire-emblem",me);

	if( !str )	return 0;

	if( str == "fire" )
	{
	  if( !ob1 || !ob2 )
	  {
	  message_vision("沒有任何反應。\n",me);
	  }else{
	    if( ob2->query("specialitem") == 1 && ob1->query("spirit") == 1 )
	    {
	    message_vision("\n"+ob1->query("name")+HIR"和"NOR+ob2->query("name")+HIR"感受到一股無形的力量，緩緩飄浮在空中，\n赤紅的火舌絲絲的從"NOR+ob1->query("name")+HIR"和"NOR+ob2->query("name")+HIR"不時吐露。\n" + NOR,me);
	    me->force_me("change unarmed");
	    me->start_busy(10);
	    call_out("compose1",5,me);
	    }else{
	    message_vision("沒有任何反應。\n",me);
	    }
	  }
	}else{
	message_vision("$N做了幾個詭異的動作，卻不見有什麼反應。\n",me);
	}
	return 1;
}
int compose1(object me)
{
	object ob,ob1,ob2;
	me=this_player();
	ob=this_object();
	ob1=present("fire-spirit",me);
	ob2=present("fire-emblem",me);
	message_vision("\n"+ob1->query("name")+NOR+HIR"和"NOR+ob2->query("name")+NOR+HIR"釋出的陣陣赤紅火舌慢慢的籠照" + HIY + "$N"NOR+HIR"四周圍，\n身盼的溫度愈來愈高，彷彿連空氣都將快要蒸發。\n" + NOR,me);
	me->start_busy(10);
	call_out("compose2",5,me);
	return 1;
}
int compose2(object me)
{
	object ob,ob1,ob2,ob3,*aob;
	int i,j;
	me=this_player();
	ob=this_object();
	aob = all_inventory(me);
	i=sizeof(aob);
	ob1=present("fire-spirit",me);
	ob2=present("fire-emblem",me);

	for( j=i-1;j>=0;j-- )
	{
	  if( aob[j]->query("dev_wp") )
	  ob3 = aob[j];
	}
        write_file("/log/sky/powerup_claw",sprintf("%s(%s)使用了%s和%s加強了%s的型態於 %s\n",me->name(1),me->query("id"),ob1->query("name"),ob2->query("name"),ob3->query("name"),ctime(time())));
	message_vision(HIR + "\n只見"+ob3->query("name")+NOR+HIR"將四周圍所有的高溫火燄全部吸收而轉變為一個完全的形態！\n" + NOR,me);
	me->set("weapon/fire-full",1);	//融合完畢後，武器呈現最完美狀態給給定的query。
	message_vision(ob1->query("name")+NOR+RED"和"NOR+ob2->query("name")+NOR+RED"所蘊藏的能量在被吸收殆盡後，也化為虛無消失無蹤。\n" + NOR,me);
	destruct(ob1);
	destruct(ob2);
	me->delete_busy();
	return 1;
}
