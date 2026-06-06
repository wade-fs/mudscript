//光之神殿 by frequency
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIY + "皇陵" + NOR + "-" + HIW + "永眠ソ地" + NOR);
  set ("long", @LONG
一座巨大的石塚佇立於此，顯然這裡曾埋葬了不少人，然而由
墓碑(tomb)上的文獻判斷，得以在此長眠的，皆是對世間有著無法
抹滅之貢獻的歷代英雄，想到此，令人不禁肅然起敬。
LONG);

  set("exits", ([
  "south" : __DIR__"tomb5.c",
               ]));
  set("valid_startroom",1);
  set("no_transmit",1);
  set("ho_scale",1);
  set("hall",1);
  set("item_desc", ([ 
  "tomb" : "墓誌銘：『安息！英魂。願化守護時代之星辰，永世光耀汝等所愛之人間。』。\n",
                     ]));
  set("search_desc", ([ 
  "tomb" : "墓碑上有些許\骯髒，要拂拭乾淨嗎(clear)？或者帶著敬仰的心祭拜眾英雄(pray)。\n",
                      ]));

  setup();
}

void init()
{
    add_action("do_pray","pray");
    add_action("do_clear","clear");
	add_action("do_blend","blend");
}

int do_pray(string str)
{
  object me = this_player();
  string att =  me->query("attribute");
  
  if(att != "saint" && (!str || str != "tomb"))
   {
          write("你立志要讓自己也要成為一位偉大的英雄。\n");
   }else{ 
         if(str)
         {
           if(str == "tomb")
           {
            if(present("light-spirit",me))
             {
              write("你身上的英雄光之魂突然嗡嗡作響，緩緩飛向陵塚。\n");
              write("光之魂似乎期待著和你兵器的融合(blend light)\n");
             }else write("ㄧ陣譏諷由墓中傳出：『沒有英雄之魂逞什麼英雄呢。』\n");
           }else{
                if(att == "saint")   write("啊你是在拜什麼東西啊!?\n");
                }
         }else{
                if(!me->query_temp("pray_saint"))
                 {
                   write("你立志要讓自己也要成為一位偉大的英雄，頓時精神大振。\n");
                   me->receive_curing("gin",1000);
                   me->receive_heal("gin",1000);
                   me->receive_curing("kee",1000);
                   me->receive_heal("kee",1000);
                   me->receive_curing("sen",1000);
                   me->receive_heal("sen",1000);
                   me->clear_condition();
                   call_out("remove_saint",120,me); 
                   me->set_temp("pray_saint",1);
                 }else write("你悠然神遊於傳說的英雄事蹟當中。\n");
              }
       }
       return 1;
}

int remove_saint(object me)
{
   me = this_player();
   remove_call_out("remove_saint");
   me->delete_temp("pray_saint");
}

int do_clear()
{
  object me,mob,ob;
  string id;
  me = this_player();
  id = me->query("id");
  if(me->query_temp("quest/return_sha") && me->query_temp("quest/return_sha")==6)
  {
    write("你擦拭墓碑的同時，發現了生命之水，便趕緊偷偷藏入懷中。\n");
	ob = new("/open/ghost-hole/obj/living-water");
	ob->move(me);
	ob->set_temp("finder",id);
	mob = new("/open/capital/room/king/npc/snow_nan");
	//mob = new(__DIR__"snow_nan");
	mob->move(environment(me));
	mob->command("say 大膽狂徒，竟敢在皇陵撒野，看招!!");
	mob->kill_ob(me);
	me->start_busy(1);
	return 1;
  }
  if(me->query("attribute") == "saint")
  {
  	message_vision(HIR + "墓塚內傳來ㄧ陣天音：『$N，今後救世的責任就交到你手上嘍，回去降妖除魔吧。』\n" + NOR,me);
  	me->move("/open/common/room/inn");
  	message_vision(HIR + "一道神光壟罩之下，$N現身於光幕之中。\n" + NOR,me);
  }else{
        write("你悠然神遊於傳說的英雄事蹟當中。\n");
        }
  return 1;
}

int do_blend(string str)
{
	object me,ob,ob1,ob2;
	me=this_player();
	ob=this_object();
	ob1=present("light-spirit",me);
	ob2=present("light-emblem",me);

	if( !str )	return 0;

	if( str == "light" )
	{
	  if( !ob1 || !ob2 )
	  {
	  message_vision("沒有任何反應。\n",me);
	  }else{
	    if( ob2->query("specialitem") == 1 && ob1->query("spirit") == 1 )
	    {
	    message_vision("\n"+ob1->query("name")+HIY + "和" + NOR+ob2->query("name")+HIY + "感受到一股無形的力量，緩緩飄浮在空中，\n墓碑內不斷湧出浩然正氣，滲入" + NOR+ob1->query("name")+HIR + "和" + NOR+ob2->query("name")+HIY + "之中。\n" + NOR,me);
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
	ob1=present("light-spirit",me);
	ob2=present("light-emblem",me);
	message_vision(HIY + "\n長眠於此的英魂似乎甦醒了過來。\n"+ob1->query("name")+NOR+HIY + "和" + NOR+ob2->query("name")+NOR+HIY + "吸收了英魂之氣後，逐漸在" + HIW + "$N" + NOR+HIY + "四周圍繞。\n" + NOR,me);
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
	ob1=present("light-spirit",me);
	ob2=present("light-emblem",me);

	for( j=i-1;j>=0;j-- )
	{
	  if( aob[j]->query("dev_wp") )
	  ob3 = aob[j];
	}
        write_file("/log/sky/powerup_claw",sprintf("%s(%s)使用了%s和%s加強了%s的型態於 %s\n",me->name(1),me->query("id"),ob1->query("name"),ob2->query("name"),ob3->query("name"),ctime(time())));
	message_vision(HIY + "\n只見"+ob3->query("name")+NOR+HIY + "完全吸收了歷代英魂給予的浩然正氣，化為最後的型態！\n" + NOR,me);
	me->set("weapon/saint-full",1);	//融合完畢後，武器呈現最完美狀態給給定的query。
	message_vision(ob1->query("name")+NOR+YEL + "和" + NOR+ob2->query("name")+NOR+YEL + "所蘊藏的能量在被吸收殆盡後，也化為虛無消失無蹤。\n" + NOR,me);
	destruct(ob1);
	destruct(ob2);
	me->delete_busy();
	return 1;
}
