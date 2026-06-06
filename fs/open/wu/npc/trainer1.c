// trainer.c
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("任朝陽", ({ "trainer jen", "jen" }) );
        set("title", "瀧山派第八代奧義任家傳人");
        set("nickname", "酒狂");
        set("gender", "男性" );
        set("age",30);
        set("str", 30);
        set("int", 24);

        set("long",
                 "任朝揚是瀧山派奧義的任家傳人, 亦是任家的長子, 他所使用的『瀧山\n" +
                 "絕學』(Lungshan)是其父正晴館主親授之絕學, 由於身為長子必須以發\n" +
                 "揚瀧山派為己任, 因此自小勤於習武, 其拳術與其父不分軒冕, 但是他\n" +
                 "嗜酒如命, 卻不至沈醉, 將醉步溶入絕學中, 使其更勝一籌, 有青勝藍\n" +
                 "之勢, 同時曾獲得城中武術冠軍, 所以大家都稱他為『 酒狂 』！\n");

        set("attitude", "heroism");

        set("combat_exp", 300000);
        set("force",800);
        set("max_force", 800);
        set("force_factor", 10);

        set("inquiry", ([
                "here": "這裡是任家正晴武館, 請問有何事指教?\n",
                "name": "在下姓任, 名朝陽, 是本館的副館主。",
                "lungshan": "喔....此為本館絕學, 在下對此頗有研究,承蒙家父栽培!\n",
        ]) );

        set_skill("unarmed" , 80);
        set_skill("lungshan", 90);
        set_skill("dodge"   , 60);
        set_skill("force"   , 60);

        map_skill("unarmed", "lungshan");
        map_skill("dodge"  , "lungshan");
        map_skill("force"  , "haoforce");

        setup();
         carry_object(__DIR__"obj/fight_robe")->wear();
carry_object("/open/wu/npc/obj/fireclaw.c")->wield();
         carry_object(__DIR__"obj/armband")->wear();
}

int recognize_apprentice(object ob)
{
        if( (string)ob->query("family/family_name")=="瀧山派" ) return 1;

        command("say 對不起﹐這位" + RANK_D->query_respect(ob) + "﹐您不是我們武館的弟子。");
        return notify_fail( "任朝陽不願意教你拳法。\n");
}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="瀧山派" ) {
                command("nod");
                command("say 來吧!");
                return 1;
        }
        command("say 館主吩咐過﹐不許\和來這裡的客人過招。");
        return 0;
}
