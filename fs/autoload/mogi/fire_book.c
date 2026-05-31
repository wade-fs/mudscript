// 魔界之書

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR"極火真經"NOR, ({ "fire_book" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			"這是一本書皮呈火紅色，隱隱有火焰發散的秘集。只有經魔王親傳
極火金身心法的人才能看(read fire_book)。\n");
		set("value", 10);
		set("material", "paper");
	}
        setup();
}

void init()
{
add_action("do_read","read");
}

int do_read(string str)
{
  object me=this_player();
  if(str!="fire_book") {
  tell_object(me,"你想讀什麼?\n");
  return -1;
                       }
  else if (!me->query("quest/gold-fire")){
  tell_object(me,"你沒學過\極\火\金\身心法，看也看不懂。\n");
  return -1;
                                         }
  else if(me->query_skill("fireforce",1) > 1){
  tell_object(me,"你已經學過了。\n");
  return -1;
                                             }
  else {
  tell_object(me,"你照著書上的口訣練了一遍，身體四周開始出現火焰，剎那間
火勁已運行了一周天。

書上最後寫著：極\火\金\身用法：perform fireforce.gold-fire\n");
  me->set_skill("fireforce",25);
  return 1;
       }      
} 
