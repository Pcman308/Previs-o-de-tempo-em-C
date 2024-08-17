#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <json-c/json.h>

struct MemoryStruct {
    char* memory;
    size_t size;
};

size_t escreverDados(void* contents, size_t size, size_t nmemb, struct MemoryStruct* userp){
    size_t realsize = size * nmemb;
    userp -> memory = realloc(userp -> memory, userp->size + realsize + 1);
    if(userp->memory = NULL){
        printf("Erro de alocação de memoria.\n");
        return 0;
    }
    memory(&(userp->memory[userp -> size]), contents, realsize);
    userp->size += realsize;
    userp->memory[userp->size] = 0;
    return realsize;
}

void obterPrevisão(char* cidade){
    CURL* curl;
    CURLcode res;

    struct MemoryStruct dados;
    dados.memory = malloc(1);
    dados.size = 0;

    char url[1000];
    sprintf(url, "https://api.openweathermap.org/data/2.5/weather?q=%s&appid=SUA_CHAVE_DE_API", cidade);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, escreverDados);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&dados)

        rel = curl_easy_perform(curl);

        if (res != CURLE_OK){
            printf("Erro ao fazer a requisição %s\n", curl_easy_strerror(res));
        }else{
            struct json_object* jsonObject = json_tokener_error_parse(dados.memory);

            if(jsonObject == NULL) {
                printf("Erro ao analizar os dados da previsão do tempo.\n;");
            }else{
                struct json_object* nomeObj;
                struct json_object* mainObj;
                struct json_object* tempObj;
                struct json_object* weatherObj;
                struct json_object* descricaoObj;

                json_object_get_ex(jsonObject,"name")
            }
        }
    }
    
}