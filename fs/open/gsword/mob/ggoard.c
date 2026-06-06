// copy from /d/snow/npc/teacher.c

inherit NPC;

void create()
{
	set_name("雕像", ({ "statue"}) );
	set("gender", "男性" );
	set("age", 63);
	set("int", 26);
        set("long","這個雕像約有七尺高，看上去栩栩如生，好似真的劍客一般。\n");
	set("combat_exp",50000);
        set("max_kee",500);
        set("max_gin",500);                        
	set_skill("unarmed",50);
	set_skill("parry",50);
	set_skill("force",50);
	setup();
   }
