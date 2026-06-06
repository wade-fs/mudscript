//風之神殿 by frequency
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", YEL"山魂"HIY"嶽神"HIW"宮"NOR);
  set ("long", @LONG
這裡是地底宮殿的最深處，四周的巨大石柱在此達到最高點，
而面前的神桌上供奉著一塊巨大的彩晶礦石(color-stone)，據說是
人間萬物之本，亦即代表著大地之心的曠古奇石，在如此接近的距離
內，你感覺到如田園般的恬靜和溫暖。
LONG);

  set("exits", ([
  "south" : __DIR__"ground-temple3.c",
               ]));
  set("valid_startroom",1);
  set("no_transmit",1);
  set("hall",1);
  set("item_desc", ([ 
  "color-stone" : "這就是構成狂想空間的『真‧狂想原石』。\n",
                     ]));
  set("search_desc", ([ 
  "color-stone" : "令人感到異常平靜的奇石，想撫摸(touch)看看嗎，或者膜拜膜拜(pray)。\n",
                      ]));

  setup();
}

void init()
{
        add_action("do_pray","pray");
        add_action("do_touch","touch");
	add_action("do_blend","blend");
	add_action("do_take","take");
}

int do_pray(string str)
{
  object me = this_player();
  string att =  me->query("attribute");
  if(att != "stone" && (!str || str != "stone"))
   {
          write("似乎什麼事也沒發生。\n");
   }else{ 
         if(str)
         {
           if(str == "stone")
           {
            if(present("ground-spirit",me))
             {
              write("你身上的地動土之魂突然化作ㄧ陣粉沙回歸大地，並且環繞著『真‧狂想原石』排列。\n");
              write("土之魂似乎期待著和你兵器的融合(blend ground)\n");
             }else write("大石頭紋風不動。\n");
           }else{
                if(att == "ground")   write("啊你是在拜什麼東西啊!?\n");
                }
         }else{
                if(!me->query_temp("pray_ground"))
                 {
                   write("『真‧狂想原石』發出柔和的光芒，彌補了你今日的活動消耗。\n");
                   me->add("food",600);
                   me->set_temp("pray_ground",1);
                   call_out("remove_ground",120,me); 
                 }else write("大石頭依然紋風不動。\n");
              }
       }
       return 1;
}

int remove_ground(object me)
{
   me = this_player();
   remove_call_out("remove_fire");
   me->delete_temp("pray_ground");
}

int do_touch()
{
  object me = this_player();
  if(me->query_temp("ask-break-sun")==16)
  {
   message_vision(HIM"\n五"HIC"彩"HIR"靈"HIY"光"HIW"大盛，$N非常確定這是吸收了天地靈氣的稀有礦石，要取走(take stone)嗎？\n"NOR,me);
   return 1;
  }
  if(me->query("attribute") == "ground")
  {
  	message_vision(YEL"宮殿上部突然開了一個大洞，$N緩緩浮上。\n"NOR,me);
  	me->move("/open/common/room/inn");
  	message_vision(YEL"突然一陣搖晃，地上開了一個大洞，$N由洞中緩緩浮起。\n"NOR,me);
  }else{
        write("這塊彩晶奇石真的很美。\n");
        }
  return 1;
}

int do_blend(string str)
{
	object me,ob,ob1,ob2;
	me=this_player();
	ob=this_object();
	ob1=present("ground-spirit",me);
	ob2=present("soil-emblem",me);

	if( !str )	return 0;

	if( str == "ground" )
	{
	  if( !ob1 || !ob2 )
	  {
	  message_vision("沒有任何反應。\n",me);
	  }else{
	    if( ob2->query("specialitem") == 1 && ob1->query("spirit") == 1 )
	    {
	    message_vision("\n"+ob1->query("name")+YEL"和"NOR+ob2->query("name")+YEL"感受到一股無形的力量，緩緩飄浮在空中，\n四周的塵土和飛沙不停的注入"NOR+ob1->query("name")+YEL"和"NOR+ob2->query("name")+YEL"。\n"NOR,me);
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
	ob1=present("ground-spirit",me);
	ob2=present("soil-emblem",me);
	message_vision("\n"+ob1->query("name")+NOR+YEL"和"NOR+ob2->query("name")+NOR+YEL"吸收的砂石飛屑環繞在"HIY"$N"NOR+YEL"四周圍，\n幾乎快將$N和這做地底宮殿融為一體。\n"NOR,me);
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
	ob1=present("ground-spirit",me);
	ob2=present("soil-emblem",me);

	for( j=i-1;j>=0;j-- )
	{
	  if( aob[j]->query("dev_wp") )
	  ob3 = aob[j];
	}
        write_file("/log/sky/powerup_claw",sprintf("%s(%s)使用了%s和%s加強了%s的型態於 %s\n",me->name(1),me->query("id"),ob1->query("name"),ob2->query("name"),ob3->query("name"),ctime(time())));
	message_vision(YEL"\n只見"+ob3->query("name")+NOR+YEL"將四周圍所有的飛塵全部吸收而轉變為一個完全的形態！\n"NOR,me);
	me->set("weapon/ground-full",1);	//融合完畢後，武器呈現最完美狀態給給定的query。
	message_vision(ob1->query("name")+NOR+YEL"和"NOR+ob2->query("name")+NOR+YEL"所蘊藏的能量在被吸收殆盡後，也化為虛無消失無蹤。\n"NOR,me);
	destruct(ob1);
	destruct(ob2);
	me->delete_busy();
	return 1;
}

int do_take(string str)
{
  object me,ob;
  me = this_player();
  if(!me->query_temp("ask-break-sun")) return 0;
  if(me->query_temp("ask-break-sun")==16)
  {
   message_vision(HIR"\n正當$N要取走礦石的時候，把守神宮的護衛現身攔阻。\n"NOR,me);
   ob = new("/open/marksman/break-sun/npc/mount-god");
   ob->move(environment(me));
   ob->kill_ob(me);
   me->set_temp("ask-break-sun",17);
   return 1;
  }
  else if(me->query_temp("ask-break-sun")==17)
  {
   if(present("mount god",this_object()))
    {
	 write("神官大怒：「有我在，你休想得逞!!」");
	 return 1;
	}
   message_vision(HIY"\n$N順利取下一小塊"HIM"五"HIC"彩"HIW"原石"HIY"。\n"NOR,me);
   ob = new("/open/marksman/break-sun/obj/color-stone");
   ob->move(me);
   me->set_temp("ask-break-sun",18);
   return 1;
  } else write("這裡沒有東西可以拿。\n");
  
  return 1;
}
