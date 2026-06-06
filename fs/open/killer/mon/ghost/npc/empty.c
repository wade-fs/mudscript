inherit NPC;
 
void create()
{
   set_name("空空和尚", ({"empty monk","monk"}));
   set("race", "人類");
   set("age",70);
   set("long","在殺手墓園超渡亡魂的和尚, 一身絕藝, 高深莫測。\n");
   set("str",55);
   set("cps",50);
   set("kar",50);
   set("spi",50);
   set("int",50);
   set("cor",50);
   set("con",50);
   set("limbs", ({"頭部", "胸部", "腿部", "手臂", "臀部", "腳趾"}) );
   set("verbs", ({ "bite", "claw"}));
 
   set("attitude","herosim");
   set("combat_exp",650000);
   set("force_factor", 12);
   set("max_kee",3000);
   set("kee",3000);
   set("max_force",2000);
   set("force",2000);
  set("max_gin",1500);
  set("gin",1500);
  set("max_sen",1500);
  set("sen",1500);

   set_skill("force", 80);
   set_skill("dodge", 200);
   set_skill("blackforce", 80);
   set_skill("ghost-steps", 80);

   map_skill("force", "blackforce");
   map_skill("dodge", "ghost-steps");
 
   set("chat_chance",10);
   set("chat_msg", ({
   (: this_object(), "random_move" :),
" 空空和尚唱道: 天也空, 地也空, 人生渺渺在其中;\n
                日也空, 月也空, 東昇西墜為誰功\?\n
                金也空, 銀也空, 死後何曾在手中!\n
                妻也空, 子也空, 黃泉路上不相逢!\n
                權也空, 名也空, 轉眼荒郊土一封!\n",
" 空空和尚吟道: 菩提本無樹, 明敬亦非臺;\n
                本來無一物, 何處惹塵埃。\n",
        }));

   setup();
}


