
// master_jen.c

inherit NPC;


void create()
  {
set("class", "fighter");
        set_name("任我行", ({ "jen wu shin", "jen", "shin" }) );
        set("title","瀧山派第六代二弟子");
        set("nickname", "隴山叛徒");
        set("gender", "男性");
        set("age", 65);
        set("attitude", "aggressive");
        set("long",
"任我行是任博文的弟弟，也就是任正晴的師叔，功\夫不及任博文，但企圖心極強，曾\n"
"意圖以毒計毒殺任正晴以奪得掌門位，只可惜事跡敗漏，被任博文祕密關在隴山武館\n"
"的地下室達二十年，靠吃蟲鼠維生，已瀕臨瘋狂，見人便殺\n");

        set("str", 48);
        set("cps", 40);
        set("per", 34);
        set("int", 38);
        set("kar", 16);

       set("combat_exp",1000000);
       set("kee",2000);
       set("max_kee",2000);
        set("force"       , 2700);
        set("max_force"   , 2700);
        set("force_factor", 10);
        set("score"       , 200000);

//           set("chat_chance_combat", 80);

/*           set("chat_msg_combat", ({
                (: consider :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
          }) ); */


        set_skill("move",70);
        set_skill("unarmed", 60);
        set_skill("force", 60);
        set_skill("parry", 70);
	set_skill("dodge",80);
          set_skill("henma-steps",80);
        set_skill("lungshan",70);
        set_skill("haoforce",60);

        map_skill("force", "haoforce");
        map_skill("unarmed", "lungshan");
          map_skill("dodge", "henma-steps");

        set("chat_chance_combat",65);
        set("chat_msg_combat",({
//           (: exert_function, "enforceup" :),

            (: perform_action, "force.kang_kee"   :)
        }));



        setup();

        add_money("gold",10);
}

