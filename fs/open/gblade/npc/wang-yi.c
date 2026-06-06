inherit NPC;

void create()
{
        set_name("王義",({"wang yi","yi"}));
        set("long","
金刀門的長工，黝黑的膚色看起來更顯出身子的健朗，雖然不是金刀門的
正式弟子，但長年下來的耳濡目染，也學會了幾招簡單入門的招式。
");
        set("gender","男性");
	set("title","金刀門長工");
        set("combat_exp",2000);
        set("attitude","friendly");
        set("age",40);
	set_skill("stick",30);
	set_skill("parry",30);
        set_skill("dodge",25);
        setup();
        carry_object("/open/gsword/obj/robe.c")->wear();
	carry_object("/open/gblade/obj/broom1.c")->wield();
	add_money("coin",75);
}
