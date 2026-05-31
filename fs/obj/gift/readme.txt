講故事並發獎勵系統說明：
COPY文件storyd.c到/adm/daemons/下，在/adm/etc/perload中加入/adm/daemons/storyd.c
語句，再把gift文件架copy到/clone/下。即可自動運行，如沒自動運行，可以
update /adm/daemons/storyd.c，使其運行。
別的文件放入clone/gift
在include/globals.h
     #define STORY_DIR          "/clone/gift/"
     #define STORY_D            "/adm/daemons/storyd"
