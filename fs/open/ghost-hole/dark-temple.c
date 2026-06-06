//暗之神殿 by frequency
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "暗靈祭之廳");
  set ("long", @LONG
這裡是暗之神殿的正廳，面前ㄧ座座巨大到誇張的浮雕(statue)，
代表著統馭幽冥黃泉的十殿閻羅神像，無窮無盡的暗魔氣息正咄咄逼人
的瀰漫開來，看起來唯有暗之ㄧ族的使者才能習慣此地的氣氛。
LONG);

  set("exits", ([
  "south" : "/open/ghost-hole/g-s07",
               ]));
  set("no_fight",1);
  set("valid_startroom",1);
  set("no_transmit",1);
  set("hall",1);
  set("item_desc", ([ 
  "statue" : "每ㄧ座都雕飾得栩栩如生，顯然並非出自人手。\n",
                     ]));
  set("search_desc", ([ 
  "statue" : "你突然覺得，擅自搜索這些雕像將受到詛咒(curse)，還是懷著虔誠的心膜拜一下好了(pray)。\n",
                      ]));

  setup();
}

void init()
{
        add_action("do_pray","pray");
        add_action("do_curse","curse");
	add_action("do_blend","blend");
}

int do_pray(string str)
{
  object me = this_player();
  string att =  me->query("attribute");
  if(att != "dark" && (!str || str != "statue"))
   {
          write("突然間，十殿閻羅像魔光大盛，充沛之極的至邪妖氣由四面八方不斷湧至，你殫竭元神抵抗。\n");
          me->unconcious();
          me->set("force",1);
          me->set("atman",1);
          me->set("mana",1);
          me->set("force_factor",0);
   }else{ 
         if(str)
         {
           if(str == "statue")
           {
            if(present("dark-spirit",me))
             {
              write("你身上的心魔暗之魂突然化作ㄧ道黑芒，迅速在十殿閻羅像間遊走。\n");
              write("暗之魂似乎期待著和你兵器的融合(blend dark)\n");
             }else write("ㄧ陣惱怒的聲音由神像上傳來：『你身上沒有我想要的東西。』\n");
           }else{
                if(att == "dark")   write("啊你是在拜什麼東西啊!?\n");
                }
         }else{
                if(!me->query_temp("pray_dark"))
                 {
                   write("突然間，十殿閻羅像魔光大盛，充沛之極的至邪妖氣不斷湧入你體內，令你戰意高昂。\n");
                   me->add_temp("apply/damage",5);
                   me->add_temp("apply/attack",5);
                   me->add_temp("apply/parry",-5);
                   me->add_temp("apply/dodge",-5);
                   call_out("remove_dark",120,me); 
                   me->set_temp("pray_dark",1);
                 }else write("你只覺得，十殿閻羅看起來仍是那麼的偉大。\n");
              }
       }
       return 1;
}

int remove_dark(object me)
{
   me = this_player();
   remove_call_out("remove_dark");
   write("你身上的魔氣漸趨稀薄，最後終於消失了。\n");
     me->add_temp("apply/damage",-5);
     me->add_temp("apply/attack",-5);
     me->add_temp("apply/parry",5);
     me->add_temp("apply/dodge",5);
     me->delete_temp("pray_dark");
}

int do_curse()
{
  object me = this_player();
  if(me->query("attribute") == "dark")
  {
  	write("邪神高興的說：『很好，我就將你送回人界去興風作浪吧。』\n");
  	me->move("/open/common/room/inn");
  }else{
        write("你不禁詛咒起無聊到跑來這鬼地方亂晃的自己。\n");
        }
  return 1;
}

int do_blend(string str)
{
	object me,ob,ob1,ob2;
	me=this_player();
	ob=this_object();
	ob1=present("dark-spirit",me);
	ob2=present("dark-emblem",me);

	if( !str )	return 0;

	if( str == "dark" )
	{
	  if( !ob1 || !ob2 )
	  {
	  message_vision("沒有任何反應。\n",me);
	  }else{
	    if( ob2->query("specialitem") == 1 && ob1->query("spirit") == 1 )
	    {
	    message_vision("\n"+ob1->query("name")+BLU + "和" + NOR+ob2->query("name")+BLU + "感受到一股無形的力量緩緩的飄浮在空中，\n黑色的氣霧絲絲的從" + NOR+ob1->query("name")+BLU + "和" + NOR+ob2->query("name")+BLU + "散發出來。\n" + NOR,me);
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
	ob1=present("dark-spirit",me);
	ob2=present("dark-emblem",me);
	message_vision("\n"+ob1->query("name")+NOR+BLU + "和" + NOR+ob2->query("name")+NOR+BLU + "釋出的陣陣黑色霧氣，慢慢籠照" + HIY + "$N" + NOR+BLU + "四周圍，\n眼前的視線愈來愈昏暗，直至完全被掩沒，一片黑暗。\n" + NOR,me);
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
	ob1=present("dark-spirit",me);
	ob2=present("dark-emblem",me);

	for( j=i-1;j>=0;j-- )
	{
	  if( aob[j]->query("dev_wp") )
	  ob3 = aob[j];
	}
        write_file("/log/sky/powerup_claw",sprintf("%s(%s)使用了%s和%s加強了%s的型態於 %s\n",me->name(1),me->query("id"),ob1->query("name"),ob2->query("name"),ob3->query("name"),ctime(time())));
	message_vision(BLU + "\n只見"+ob3->query("name")+NOR+BLU + "將四周圍所有的黑色氣霧全部吸收而轉變為一個完全的形態！\n" + NOR,me);
	me->set("weapon/dark-full",1);	//融合完畢後，武器呈現最完美狀態給給定的query。
	message_vision(ob1->query("name")+NOR+BLU + "和" + NOR+ob2->query("name")+NOR+BLU + "所蘊藏的能量在被吸收殆盡後，也化為虛無消失無蹤。\n" + NOR,me);
	destruct(ob1);
	destruct(ob2);
	me->delete_busy();
	return 1;
}
