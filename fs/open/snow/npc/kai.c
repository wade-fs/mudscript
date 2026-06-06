
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
       set_name("劉颽",({"kai liu","kai","liu"}));
      set("long","
      他是劉全書的義子,劉颽,外表俊俏,充滿豪傑之氣,看起來
      像是讀書人,但是精通武學,練就了一身快手。\n");
                set("gender","男性");
	set("class","fighter");
   set("nickname",HIW"快手"NOR);
         set("combat_exp",100000);
          set("attitude","heroism");
          set("age",20);
       set("title","劉全書之義子");
          set("str",23);
          set("cor",40);
          set("cps",40);
          set("per",20);
          set("int",30);
          set("con",25);
          set("spi",20);
          set("kar",27);
          set("force",800);
          set("max_force",800);
          set("max_kee",800);
          set("kee",800);
          set_skill("dodge",60);
          set_skill("black-steps",40);
          set_skill("force",60);
          set_skill("snowforce",40);
          set_skill("parry",50);
          set_skill("snow-martial",60);
          set_skill("unarmed",60);
          set("force_factor",10);
          map_skill("unarmed","snow-martial");
          map_skill("dodge","black-steps");
          map_skill("force","snowforce");
          setup();
   carry_object("/open/snow/obj/ring.c")->wield();
      }
 
