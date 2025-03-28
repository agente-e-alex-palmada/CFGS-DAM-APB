PGDMP  (        
            |            clash    16.6    16.6     �           0    0    ENCODING    ENCODING        SET client_encoding = 'UTF8';
                      false            �           0    0 
   STDSTRINGS 
   STDSTRINGS     (   SET standard_conforming_strings = 'on';
                      false            �           0    0 
   SEARCHPATH 
   SEARCHPATH     8   SELECT pg_catalog.set_config('search_path', '', false);
                      false            �           1262    16398    clash    DATABASE     x   CREATE DATABASE clash WITH TEMPLATE = template0 ENCODING = 'UTF8' LOCALE_PROVIDER = libc LOCALE = 'Spanish_Spain.1252';
    DROP DATABASE clash;
                postgres    false            �            1259    16399    jugadors    TABLE       CREATE TABLE public.jugadors (
    id integer NOT NULL,
    nom character varying NOT NULL,
    nivell integer DEFAULT 1 NOT NULL,
    copes integer DEFAULT 0 NOT NULL,
    oro bigint DEFAULT 0 NOT NULL,
    gemes bigint DEFAULT 0 NOT NULL,
    estrelles bigint DEFAULT 0 NOT NULL
);
    DROP TABLE public.jugadors;
       public         heap    postgres    false            �            1259    16411    jugadors_id_seq    SEQUENCE     �   ALTER TABLE public.jugadors ALTER COLUMN id ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public.jugadors_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);
            public          postgres    false    215            �            1259    16412    partides    TABLE     �   CREATE TABLE public.partides (
    id integer NOT NULL,
    resultat character varying,
    temps character varying,
    tipus character varying,
    idjugador1 integer NOT NULL,
    idjugador2 integer NOT NULL
);
    DROP TABLE public.partides;
       public         heap    postgres    false            �          0    16399    jugadors 
   TABLE DATA           Q   COPY public.jugadors (id, nom, nivell, copes, oro, gemes, estrelles) FROM stdin;
    public          postgres    false    215   �       �          0    16412    partides 
   TABLE DATA           V   COPY public.partides (id, resultat, temps, tipus, idjugador1, idjugador2) FROM stdin;
    public          postgres    false    217   �       �           0    0    jugadors_id_seq    SEQUENCE SET     >   SELECT pg_catalog.setval('public.jugadors_id_seq', 1, false);
          public          postgres    false    216            Z           2606    16410    jugadors jugadors_pkey 
   CONSTRAINT     T   ALTER TABLE ONLY public.jugadors
    ADD CONSTRAINT jugadors_pkey PRIMARY KEY (id);
 @   ALTER TABLE ONLY public.jugadors DROP CONSTRAINT jugadors_pkey;
       public            postgres    false    215            \           2606    16418    partides partides_pkey 
   CONSTRAINT     T   ALTER TABLE ONLY public.partides
    ADD CONSTRAINT partides_pkey PRIMARY KEY (id);
 @   ALTER TABLE ONLY public.partides DROP CONSTRAINT partides_pkey;
       public            postgres    false    217            �   9   x�3�H,�L-�4�4�@.#NǼ��$c��9�H"&�(*L9K��1z\\\ \��      �   b   x�M�1
�0뽿Dr�K����AD��~/�`���lDp��ck��B
��G#�l��z�g[*��Y�l�y���n�d3�،ٲ|?lξ�b�     