// apprentice.c

#include <dbase.h>
#include <basic_skill.h>

int is_apprentice_of(object ob)
{
	mapping family;
	
	if( !mapp(family = query("family")) ) return 0;

    if( family["master_id"] == (string)ob->query("id") )
		return 1;

	return 0;	
}

void assign_apprentice(string title, int privs)
{
	mapping family;

	if( !mapp(family = query("family")) ) return;

	family["title"] = title;
	family["privs"] = privs;

	if( userp(this_object()) || !query("title") ) {
		if( family["generation"]==1 )
			set("title", family["family_name"] + "開山祖師");
		else
			set("title", sprintf("%s第%s代%s%s",
			  family["family_name"],
			  chinese_number(family["generation"]),
			  query("gender")=="男性"?"":"女",
			  family["title"]));
	}
}

// This is used for NPC, or start a new family for a player.
void create_family(string family_name, int generation, string title)
{
	mapping family;

	family = allocate_mapping(6);

	family["family_name"] = family_name;
	family["generation"] = generation;

	set("family", family);

	// priv = -1 for ALL privileges.
	assign_apprentice( title, -1 );
}

int recruit_apprentice(object ob)
{
	mapping my_family, family;
	mapping skills;
	string *skname;
	int old_lv, new_lv, i;

	if( ob->is_apprentice_of( this_object() ) )	return 0;
	if( !mapp(my_family = query("family")) ) return 0;

	// 把玩家判師要扣特殊技能的處罰加在這裡 by Oda 96/6/5
	if( ob->query("family") ) {
		skills = ob->query_skills();
		if( mapp(skills) ) {
			skname = keys( skills );
			for(i=0; i<sizeof(skname); i++)
			  // wade 2002-11-13 因為玩家太少了
			  // 要遇到很難，因此叛師之風要鼓勵一下，force 降少一點
                          if (skname[i] == "force") {
				old_lv = ob->query_skill(skname[i],1);
				if (old_lv > 10)
					ob->set_skill(skname[i],old_lv-1);
				else
					ob->set_skill(skname[i],old_lv);
                          }
			  else if( undefinedp(basic_skill[skname[i]])) {
				old_lv = ob->query_skill(skname[i],1);
				// wade 2002-11-13 同上
				// new_lv = old_lv * 2/3;
				new_lv = old_lv * 0.9;
				ob->set_skill(skname[i],new_lv);
			  }
		}
		tell_object(ob, "為了加入新門派﹐你自願將特殊技能扣掉三分之一。\n\n");
	}

	family = allocate_mapping(sizeof(my_family));
	if (undefinedp(my_family["next_title"]))
	  // if (ob->query("gender") == "男性")
	    my_family["next_title"] = "弟子";
	  // else
	  //   my_family["next_title"] = "女弟子";
	else
	  family["next_title"] = my_family["next_title"];
	    

	family["master_id"] = query("id");
	family["master_name"] = query("name");
	family["family_name"] = my_family["family_name"];
	family["generation"] = my_family["generation"] + 1;
	family["enter_time"] = time();
	ob->set("family", family);
	ob->assign_apprentice(my_family["next_title"], 0);

	return 1;
}

