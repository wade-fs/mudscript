inherit NPC;

void create()
{
	set_name("白虎", ({"white tiger","tiger"})) ;
	set("race", "野獸");
	set("age",20);
set("long","白年難得一見的白虎,有著白雪一般的毛色,它正安祥的躺在地上,對於你
的出現,並不住太注意,也許\,甚少有人敢向它挑戰吧!\n");
	set("str",60);
	set("con",50);
	set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
		
        set("attitude","friendly");
	set("kee",600);
	set("combat_exp",41280);
	set("max_kee",600);
	set_temp("apply/armor",40);
	set_temp("apply/dodge",40);
	set_temp("apply/attack",40);
	setup();
}

