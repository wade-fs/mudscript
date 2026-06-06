inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("段雲",({"lord duan","lord","duan"}));
        set("long","段雲便是當今皇上冊封的平南王, 同時也是段家武學的第十代傳人, "+
"雖然貴為王爺, 自有一肚子的墨水, 但其一身祖傳的武學卻也沒忘, 可說是文武雙全, "+
"也因為如此, 段雲自是非常重視文學素養, 若想拜入段家武學的門下, 則非是一位書生不可。\n");
        set("gender","男性");
        set("class","scholar");
        set("nickname","平南王");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("age",50);
        set("str", 44);
        set("cor", 24);
        set("cps", 18);
        set("per", 24);
        set("int", 42);
        set("force",3000);
        set("max_force",3000);
        set_skill("literate",100);
        set_skill("force", 85);
        set_skill("dodge", 60);
        set_skill("move", 60);
        set_skill("parry", 40);
        set_skill("sunforce",100);
        set_skill("six-fingers",100);
        map_skill("force","sunforce");
        map_skill("unarmed","six-fingers");
        map_skill("dodge","six-fingers");
        set("force_factor",10);
        setup();
        add_money("gold",10);
        create_family("段家",10,"掌門人");
}
  void attempt_apprentice(object me)
{
        write("很好﹐" + RANK_D->query_respect(me) + "多加努力﹐"+
              "他日必定有成。\n");
        command("recruit " + me->query("id") );
}
