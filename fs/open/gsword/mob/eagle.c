inherit NPC;

void create()
{
	set_name("老鷹", ({"eagle"}));
	set("race", "野獸");
	set("age",10);
set("long","雙眼炯炯有神的大老鷹,高高的站在枝頭上俯視四方.\n");
	set("str",25);
	set("limbs", ({ "頭部", "身體","雙腳" , "雙眼"}));
	set("verbs", ({ "poke", "claw"}));
		
        set("attitude","friendly");
	set("kee",100);
	set("combat_exp",8000);
	set("max_kee",100);
	setup();
}

