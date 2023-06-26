# Documentation de Projet C++ : Système de Gestion de Prêts

Date : Juin 2023

Réalisé par : Romain DIOP & Mehdi EL AYADI

## Introduction

Le système de gestion de prêts que nous avons conçu et développé est un projet complexe qui traite de la **gestion des prêts** entre emprunteurs et prêteurs. Ce projet a été réalisé à l'aide du langage de programmation **C++**.

## Architecture du Projet

Notre projet est structuré selon une **architecture orientée objet**, qui nous a permis de bien organiser et de compartimenter les différents aspects du projet. Le diagramme de classes ci-dessus illustre cette organisation. Nous avons utilisé des concepts de base de la programmation orientée objet tels que **l'héritage** et la **généralisation** pour éviter la redondance dans le code.

La classe `Deal` est la classe principale et elle est héritée par la classe `Facility`, ce qui nous a permis d'éviter la duplication du code. Les classes `Lender`, `Borrower` et `Currency` sont des composants de base qui sont utilisés par les classes `Deal` et `Facility`. La classe `Portfolio` est utilisée pour gérer plusieurs `Facility`. L'utilisation de **surcharges** et de **polymorphisme** a également été appliquée pour améliorer la modularité du code.


![mermaid-diagram-2023-06-25-211214](http://image.noelshack.com/fichiers/2023/26/1/1687790126-cpp-diagram-2.png)

```console
C:\Users\AM\Documents\GitHub\SP_CPPBank\cmake-build-debug\SP_CPPBank.exe
Loan Details
Contract Number: D1234
Borrower: Air France
Amount: 1e+06 EUR
Starting Date: 25/06/2023
Ending Date: 24/06/2024
-----------------------------
Facility Details
Amount: 500000 USD
Repayment Schedule: 25/07/2023
Early Repayment Penalty: 0.2
Total Interest in the Portfolio: 3626.11
Making Repayment...
-----------------------------
Repayment Amount: 403626 USD
Paying back lenders:
- Agent: JP Morgan Chase
- Pool Lenders: Bank of America, Wells Fargo,
New Part Added for Repayment Cycle:
Part Repayment Date: 24/08/2023
Total Interest in the Portfolio: 7252.22
Making Repayment...
-----------------------------
Repayment Amount: 307252 USD
Paying back lenders:
- Agent: JP Morgan Chase
- Pool Lenders: Bank of America, Wells Fargo,
New Part Added for Repayment Cycle:
Part Repayment Date: 23/09/2023
Loan has been fully repaid!
-----------------------------

```

## Difficultés rencontrées

Nous avons rencontré plusieurs difficultés lors du développement de ce projet. En particulier, nous avons eu du mal à gérer la **libération de la mémoire** en C++, une caractéristique spécifique de ce langage qui peut être complexe pour les développeurs débutants. En outre, nous avons eu des difficultés avec certains bugs et erreurs que nous avons dû résoudre.

Un autre problème a été la collaboration à l'aide de **Git** avec l'IDE **CLion**. Nous avons rencontré des problèmes avec la synchronisation du code entre les membres de l'équipe.

## Répartition du travail

Le travail a été équitablement réparti entre les membres de l'équipe. Chaque membre a pris part à toutes les étapes du développement, de la conception à la résolution de problèmes, en passant par la rédaction du code et les tests.

## Fonctionnalités et améliorations

Notre système de gestion de prêts est capable de gérer plusieurs emprunteurs, prêteurs, deals, parties et installations. Cependant, il reste des améliorations à apporter.

Nous avons noté **l'absence d'une véritable base de données** pour stocker et gérer les données de manière plus efficace. Actuellement, toutes les données sont stockées en mémoire, ce qui n'est **pas idéal** pour un système de production réel.

De plus, notre système ne prend pas en charge les taux d'intérêt variables, ce qui pourrait être une amélioration intéressante à envisager à l'avenir.

Par ailleurs, certains points pourraient être améliorés dans notre code. Voici quelques remarques qui pourraient être prises en compte :

1. **Synchronisation entre les fichiers d'en-tête (.h) et les fichiers d'implémentation (.cpp)**: Les méthodes et attributs déclarés dans les fichiers d'en-tête devraient correspondre exactement avec les fichiers d'implémentation.

2. **Gestion de la mémoire**: Nous utilisons des pointeurs bruts dans certaines parties du code. En C++, il faut gérer manuellement l'allocation et la libération de la mémoire pour éviter les fuites de mémoire. Nous pourrions envisager d'utiliser des pointeurs plus intelligemment avec des shared et unique_ptr. 

3. **Style de code cohérent**: Il est important de maintenir un style de code cohérent. Par exemple, certaines fonctions utilisent une définition inline à l'intérieur de la déclaration de classe, tandis que d'autres sont seulement déclarées dans la classe et définies séparément.

4. **Mélange de la logique dans `main.cpp`**: Il est généralement préférable de séparer la logique et la fonctionnalité de `main.cpp`. Nous pourrions déplacer la majorité de la logique dans des méthodes à l'intérieur de nos classes.

## Conclusion

Notre projet a été un exercice intéressant et instructif pour nous. Malgré les défis rencontrés, nous avons réussi à développer un système de gestion de prêts fonctionnel. Nous avons appris à travailler ensemble, à résoudre des problèmes et à nous améliorer en tant que développeurs. Ce fut un projet stimulant qui a demandé beaucoup de réflexion et de planification malgrè un emploi du temps très chargé avec les autres projets et les examens de la fin de ce semestre. Nous sommes fiers du travail accompli et nous sommes impatients de nous attaquer à de nouveaux défis à l'avenir.
