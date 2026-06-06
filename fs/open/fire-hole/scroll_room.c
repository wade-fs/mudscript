#include <ansi.h>
inherit ROOM;

void trans_1(int ,object);
int do_transfer(string str,object);

void create ()
{
  set ("short", HIG"六芒星陣眼"NOR);
  set ("long", @LONG
耀眼的六色光芒散去，四周景象開始清晰了起來，然而你只有更加的訝異，因為
身處的地方赫然是八方皆不著邊際的宇宙空間，遙遠的星光在黑暗中不停閃爍，隱隱
和你體內的十股渾天氣勁遙遙呼應，然而有個地方的光點卻總是特別明亮...
LONG);
  set("no_transmit", 1);
  set("no_chome", 1);
  setup();
set_reset(this_object(),60);
}

void init()
{
	// 因為昏倒中的物件不會呼叫 init() 所以改到 reset()
	// 十五分鐘後就會自動開始了！
}

void reset()
{
	foreach(object u in  all_inventory()) 
	{
		call_out("trans_1",10,0,u);
		call_out("do_check",30,u); 
	}

}

void trans_1(int i,object me){
if(me->query_temp("find_scroll") == 4) {
message_vision(HIG"\n $N 不停的擬聚先天全天功\的真氣。\n"NOR,me);
if(i<10) {i++; call_out("trans_1",10,i,me);} else {call_out("do_transfer",10,"star",me); }
}
}
int do_transfer(string str,object me)
{
 object book;
  if(me->query_temp("find_scroll") == 4)
  {
    if(str == "star")
    {
      message_vision(HIG"\n$N以渾天真氣推動先天乾坤功\，朝遙遠的宇宙發出全力一擊!!\n"NOR,me);
      me->start_busy(100);
      call_out("break_star",7,me);

    }
    return 1;
  }else{

        return 0;
       }
}

void do_check(object me)
{
    if(me->query_temp("find_scroll") == 3)
    {
     message_vision(HIW"\n突然，一陣怪異的流星雨高速襲來，$N抵抗不住星之力的強大衝擊，當場暈厥...\n\n"NOR,me);
     me->unconcious();
     call_out("do_revive",5,me);
     }
}

int do_revive( object me )
{
        remove_call_out("do_revive");
        me->revive();
        me->set("kee",me->query("max_kee"));
        me->set("sen",me->query("max_sen"));
        me->set("gin",me->query("max_gin"));
        me->move( __DIR__"dream.c");
        return 1;
}

int break_star( object me )
{
        message_vision(HIG"\n這股石破天驚的勁力，輕易的突破了次元障礙，直衝最明亮的恆星。將其爆個粉碎。\n"NOR,me);
        call_out("got_book",8,me);
        return 1;
}

int got_book(object me)
{
  object book;
  message_vision(HIG"\n碎石堆中出現一本泛黃的古書，迅速穿越數萬光年，浮現在$N眼前，$N下意識的將它收入懷中。\n"NOR,me);
  book = new("/open/fire-hole/obj/universe_book");
  book->move(me);
  call_out("back_home",5,me);
  return 1;
}

int back_home(object me)
{
  message_vision(HIW"\n封印破除，$N立刻自扭曲的時空回到原來世界。\n"NOR,me);
  me->delete_busy();
  me->move("/open/fire-hole/fire1");	
}
