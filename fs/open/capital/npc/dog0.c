// by Onion
#include <command.h>
inherit NPC;

void create()
{
	set_name("凶惡的獒犬", ({ "bad dog","dog" }) );
        set("race", "野獸");
	set("age", 15);
	set("long", "非常具有攻擊性的狗, 隨時想要撲上來咬你一口的樣子。\n");
	set("str", 100);
        set("max_kee", 800);
        set("limbs", ({ "頭部", "身體", "前腳" , "後腳" , "尾巴" }) );
        set("verbs", ({ "bite"}));
        set("combat_exp",15000);
        set("attitude","aggressive");
	set_temp("apply/damage", 70);
        set_temp("apply/attack", 30);
	setup(); 
}
void greeting(object who)
{
	if( !is_killing(who) )
		write(name()+"朝著你撲過來, 似乎想把你給撕裂一般。\n");
}
int follow_me(object who, string dir)
{
	object ob=this_object();
	if ( !living(ob) || who==ob )
		return 0;
        call_out("delay_follow", 1, ob, dir);
        return 1;
}
void delay_follow(object ob,string dir)
{
        GO_CMD->main(ob, dir);
}
