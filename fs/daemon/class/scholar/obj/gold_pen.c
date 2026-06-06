//whip.c

#include <weapon.h>

inherit STABBER;

int special_att();

void create()
{
	object me=this_player();
	set_name("御賜金筆", ({"golden pen", "pen", "golden"}) );
        set_weight(300);
	if( clonep() )
	 set_default_object(__FILE__);
	else 
	 {
	  set("unit", "支");
	  set("long","這是當今聖上賜給楊書文尚書的金筆﹐感念他為國的辛勞。\n");
	  set("value", 10000);
	  set("material", "blacksteel");
	 }
    init_stabber(65);
	me->set("chat_chance_combat",10);
	me->set("chat_msg_combat", ({
	(: this_object(),"special_att" :),
         		}));       
	setup();
}

int special_att()
{
	object me=this_player(),*enemy=me->query_enemy();
	int i=sizeof(enemy),j;
	string *busy_msg=({
	"楊書文緊握御賜金筆著往你胸前一點﹐你突然覺得動作遲鈍了起來!!\n",
	"楊書文用御賜金筆直刺你小腿﹐使你撲通一聲﹐跌倒在地。\n",
	"楊書文將御賜金筆虛晃一招﹐趁機點了你手臂﹐你感到真氣窒礙難行。\n"
	});
        int k=sizeof(busy_msg);
        j=random(i);
        tell_room(environment(me),"突然間"+me->query("name")+"飛快的往"+
        enemy[j]->query("name")+"身上一點...\n",enemy[j]);
	if( enemy[j] && living(enemy[j]) )
	 { 
	  tell_object(enemy[j],""+busy_msg[random(k)]+"");
 	  enemy[j]->start_busy(random(3)+1);
 	 } 
}	
