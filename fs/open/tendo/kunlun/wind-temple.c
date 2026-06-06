//風之神殿 by frequency
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIW + "雲頂" + YEL + "‧" + HIG + "風" + GRN + "翔" + HIY + "殿" + NOR);
  set ("long", @LONG
永不止息的清風緩緩地在四周流過，強風的怒咆似乎被這清風完全
阻絕在外，世上流動空氣都由此地聖靈所掌管，然而聖靈來無影去無蹤
，你只依稀看到面前扭曲的空間之中隱隱浮現一團清煙(smog)，即自古
就統御著時空流動的全能主宰......
LONG);

  set("exits", ([
  "south" : __DIR__"time.c",
               ]));
  set("no_fight",1);
  set("valid_startroom",1);
  set("no_transmit",1);
  set("hall",1);
  set("item_desc", ([ 
  "smog" : "隱藏著時間和空間密奧的虛幻靈體。\n",
                     ]));
  set("search_desc", ([ 
  "smog" : "要嘗試一探時空奧秘嗎(touch)，或者懷著敬畏的心膜拜一下就好了(pray)。\n",
                      ]));

  setup();
}

void init()
{
        add_action("do_pray","pray");
        add_action("do_touch","touch");
	add_action("do_blend","blend");
}

int do_pray(string str)
{
  object me = this_player();
  string att =  me->query("attribute");
  if(att != "smog" && (!str || str != "smog"))
   {
          write("突然間狂風大作，怒嚎著的神風將你緊緊包圍，你感到五馬分屍般的撕新裂肺之苦。\n");
          me->unconcious();
          me->set("force",1);
          me->set("atman",1);
          me->set("mana",1);
          me->set("force_factor",0);
   }else{ 
         if(str)
         {
           if(str == "smog")
           {
            if(present("wind-spirit",me))
             {
              write("你身上的天翔風之魂突然化作ㄧ道清煙，迅速飛向面前的靈煙。\n");
              write("風之魂似乎期待著和你兵器的融合(blend wind)\n");
             }else write("ㄧ陣惱怒的聲音由靈煙中傳來：『你身上沒有我想要的東西。』\n");
           }else{
                if(att == "fire")   write("啊你是在拜什麼東西啊!?\n");
                }
         }else{
                if(!me->query_temp("pray_wind"))
                 {
                   write("一道神風在你身旁擦過，你感覺體態輕盈，四肢靈動。\n");
                   me->add_temp("apply/move",10);
                   me->add_temp("apply/dodge",10);
                   call_out("remove_wind",120,me); 
                   me->set_temp("pray_wind",1);
                 }else write("風緩緩的在你身旁流動著。\n");
              }
       }
       return 1;
}

int remove_wind(object me)
{
   me = this_player();
   remove_call_out("remove_wind");
   write("神風的祝福散去，你感覺身子頓了一下。\n");
     me->add_temp("apply/move",-10);
     me->add_temp("apply/dodge",-10);
     me->delete_temp("pray_wind");
}

int do_touch()
{
  object me = this_player();
  if(me->query("attribute") == "wind")
  {
  	message_vision(HIG + "一陣清風包圍了$N，向雲底飛去。\n" + NOR,me);
  	me->move("/open/common/room/inn");
  	message_vision(HIG + "$N隨著一陣清風緩緩由天而降。\n" + NOR,me);
  }else{
        write("清風緩緩的在身旁拂過，真舒服。\n");
        me->add("water",-10);
        }
  return 1;
}

int do_blend(string str)
{
	object me,ob,ob1,ob2;
	me=this_player();
	ob=this_object();
	ob1=present("wind-spirit",me);
	ob2=present("wind-emblem",me);

	if( !str )	return 0;

	if( str == "wind" )
	{
	  if( !ob1 || !ob2 )
	  {
	  message_vision("沒有任何反應。\n",me);
	  }else{
	    if( ob2->query("specialitem") == 1 && ob1->query("spirit") == 1 )
	    {
	    message_vision("\n"+ob1->query("name")+HIG"和"NOR+ob2->query("name")+HIG"感受到一股無形的力量，緩緩飄浮在空中，\n陣陣宜人清風從"NOR+ob1->query("name")+HIG"和"NOR+ob2->query("name")+HIG"中向外不斷吹拂。\n" + NOR,me);
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
	ob1=present("wind-spirit",me);
	ob2=present("wind-emblem",me);
	message_vision("\n"+ob1->query("name")+NOR+HIG"和"NOR+ob2->query("name")+NOR+HIG"放出的陣陣清風慢慢的籠照" + HIY + "$N"NOR+HIG"四周圍，\n漸漸的，連空間和時間都開始扭曲起來，好像要將$N帶到另一個時空。\n" + NOR,me);
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
	ob1=present("wind-spirit",me);
	ob2=present("wind-emblem",me);

	for( j=i-1;j>=0;j-- )
	{
	  if( aob[j]->query("dev_wp") )
	  ob3 = aob[j];
	}
        write_file("/log/sky/powerup_claw",sprintf("%s(%s)使用了%s和%s加強了%s的型態於 %s\n",me->name(1),me->query("id"),ob1->query("name"),ob2->query("name"),ob3->query("name"),ctime(time())));
	message_vision(HIG + "\n只見"+ob3->query("name")+NOR+HIG"緩緩翻滾於扭曲的時空之中，將時空的震盪轉化為自體能量。\n" + NOR,me);
	me->set("weapon/wind-full",1);	//融合完畢後，武器呈現最完美狀態給給定的query。
	message_vision(ob1->query("name")+NOR+GRN"和"NOR+ob2->query("name")+NOR+GRN"所蘊藏的能量在被吸收殆盡後，也化為虛無消失無蹤。\n" + NOR,me);
	destruct(ob1);
	destruct(ob2);
	me->delete_busy();
	return 1;
}
