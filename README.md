# Position-based-dynamic
Projet réalisé en collaboration avec **Ismail WAHOUB** dans le cadre du cours électif de C++ dispensé en deuxième année à l'ENSMN. Ismail a codé les bases du projet, tandis que Martin a pris en charge son optimisation, sa sécurisation, et son raffinement.

La documentation du code (README et commentaires /**/) ont été généré automatiquement (ou partiellement) par **ChatGPT** et **Doxygen**, car rédiger manuellement des commentaires exhaustifs peut s'avérer fastidieux et maladroits. Les commentaires ont bien sûr été relus.

## Philosophie et Objectifs:
Ce projet s'appuie sur les bonnes pratiques de programmation en C++, un langage complexe et puissant. Une grande attention a été portée à la **qualité du code**, à la **gestion des ressources**, et à la **sécurité**. 

Bien que le projet vise un code propre et optimisé, des axes d'amélioration subsistent pour atteindre une efficacité et une maintenabilité maximales.

## Caractéristiques Principales
1. Bonne utilisation des concepts modernes de C++
`std::unique_ptr` : Gestion intelligente des ressources, notamment pour les vecteurs pouvant contenir un grand nombre d'objets.
Rvalue References : Optimisation des copies via ces derniers.
Gestion des dépendances circulaires : Résolution soignée des dépendances pour éviter les problèmes de compilation.

2. Fonctionnalités implémentées: 
- Une **simulation physique** de particules avec des colliders (plans et sphères).
- Ajout d'une particule lors de la réalisation d'un double clic gauche de la souris.
- Une **barre de menu** permettant de **réinitialiser** la simulation.
- Un **exemple** implémenté par défaut.
- Ajout d'une **vitesse maximum** pour éviter les vitesses abérantes (surtout quand une particule est généré dans un objet).

## Améliorations possibles

- **PlanColliders non infinis**.
- **Gestion des collisions complexes** :Résolution des problèmes liés à la génération de particules à l'intérieur des colliders ou d'autres particules.
- **Objets composés** : Ajout de connexions entre particules pour créer des objets plus complexes comme des chaînes ou des structures non rigides.
- **Ajout d'exemples interactifs** : Intégration de configurations préconstruites supplémentaires dans le menu.
- **Réalisation d'un flipper** :Inspiration d’une suggestion d’un autre binôme pour simuler un flipper.

## Autre
- Les équations implémentés ne sont pas totalement identiques à celles proposés par manque de compréhension de ces dernières (il y a sans doute aussi des erreurs dans ces dernières)
