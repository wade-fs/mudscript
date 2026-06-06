// copy from /d/snow/npc/teacher.c

inherit NPC;

void create()
{
	set_name("一位仙風道骨的老者", ({ "oldman","man"}) );
	set("gender", "男性" );
	set("age", 63);
	set("int", 26);
set("long","眼前這位老者已年近七十，但仍雙眼炯炯有神，一身內力外功均趨爐火純青之境。\n");
	set("combat_exp",5747);
        set("chat_chance_combat",6);
	set("chat_msg_combat",({
"掌門有令，任何人不得進入禁地，你們還是請回吧，\n
今日之事，我不追究就是了。否則的話，嘿嘿，別怪我手下無情。\n"}));
        set("max_kee",500);
        set("max_gin",500);                        
	set("attitude","aggressvie");
	set_skill("unarmed",50);
	set_skill("parry",50);
	set_skill("force",50);
	setup();
   }

