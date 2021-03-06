-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Generation Time: May 22, 2020 at 02:06 PM
-- Server version: 5.7.26
-- PHP Version: 7.2.18

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `dossier_juin_2020`
--

-- --------------------------------------------------------

--
-- Table structure for table `bouteille`
--

DROP TABLE IF EXISTS `bouteille`;
CREATE TABLE IF NOT EXISTS `bouteille` (
  `idBouteille` int(11) NOT NULL AUTO_INCREMENT,
  `dateAchat` date DEFAULT NULL,
  `prixAchat` int(11) DEFAULT NULL,
  `contenance` int(11) NOT NULL,
  `degreAlcool` int(11) DEFAULT NULL,
  `idVin` int(11) NOT NULL,
  `idEmplacement` int(11) DEFAULT NULL,
  `idConsommation` int(11) DEFAULT NULL,
  `idFournisseur` int(11) DEFAULT NULL,
  PRIMARY KEY (`idBouteille`),
  KEY `idVin` (`idVin`),
  KEY `idEmplacement` (`idEmplacement`),
  KEY `idConsommation` (`idConsommation`),
  KEY `idFournisseur` (`idFournisseur`)
) ENGINE=InnoDB AUTO_INCREMENT=91 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `bouteille`
--

INSERT INTO `bouteille` (`idBouteille`, `dateAchat`, `prixAchat`, `contenance`, `degreAlcool`, `idVin`, `idEmplacement`, `idConsommation`, `idFournisseur`) VALUES
(59, '2018-09-06', 2595, 750, 130, 67, NULL, NULL, 3),
(60, '2018-09-06', 2595, 750, 130, 67, NULL, NULL, 3),
(61, '2018-09-06', 2595, 750, 130, 67, NULL, NULL, 3),
(62, '2018-09-06', 2595, 750, 130, 67, NULL, NULL, 3),
(63, '2018-09-06', 2595, 750, 130, 67, NULL, NULL, 3),
(64, '2018-09-06', 2595, 750, 130, 67, NULL, 12, 3),
(65, '2019-06-15', 1245, 600, 180, 74, NULL, NULL, 1),
(66, '2019-06-15', 1245, 600, 180, 74, NULL, NULL, 1),
(67, '2019-06-15', 1245, 600, 180, 74, NULL, NULL, 1),
(68, '2019-06-15', 1245, 600, 180, 74, NULL, NULL, 1),
(69, '2019-06-15', 1245, 600, 180, 74, NULL, NULL, 1),
(70, '2019-06-15', 1245, 600, 180, 74, NULL, NULL, 1),
(71, '2019-06-15', 1245, 600, 180, 74, NULL, NULL, 1),
(72, '2019-06-15', 1245, 600, 180, 74, NULL, NULL, 1),
(73, '2016-02-10', 4250, 800, 330, 75, 1, NULL, NULL),
(74, '2012-06-06', 1450, 700, 235, 71, 3, NULL, NULL),
(75, '2017-08-09', 2345, 600, 155, 70, NULL, NULL, 9),
(76, '2017-08-09', 2345, 600, 155, 70, NULL, 11, 9),
(77, '2017-08-09', 2345, 600, 155, 70, NULL, NULL, 9),
(78, '2017-08-09', 2345, 600, 155, 70, NULL, NULL, 9),
(79, '2017-08-09', 2345, 600, 155, 70, NULL, NULL, 9),
(80, '2017-08-09', 2345, 600, 155, 70, NULL, NULL, 9),
(81, '2018-05-09', 4050, 650, 160, 76, NULL, NULL, NULL),
(82, '2018-05-09', 4050, 650, 160, 76, NULL, NULL, NULL),
(83, '2018-05-09', 4050, 650, 160, 76, NULL, NULL, NULL),
(84, '2018-05-09', 4050, 650, 160, 76, NULL, NULL, NULL),
(85, '2018-05-09', 4050, 650, 160, 76, NULL, NULL, NULL),
(86, '2018-05-09', 4050, 650, 160, 76, NULL, NULL, NULL),
(87, '2018-05-09', 4050, 650, 160, 76, NULL, NULL, NULL),
(88, '2018-05-09', 4050, 650, 160, 76, NULL, NULL, NULL),
(89, '2018-05-09', 4050, 650, 160, 76, NULL, NULL, NULL),
(90, '2018-05-09', 4050, 650, 160, 76, NULL, NULL, NULL);

-- --------------------------------------------------------

--
-- Table structure for table `consommation`
--

DROP TABLE IF EXISTS `consommation`;
CREATE TABLE IF NOT EXISTS `consommation` (
  `idConsommation` int(11) NOT NULL AUTO_INCREMENT,
  `DateConsommation` date NOT NULL,
  `notesConsommation` varchar(500) DEFAULT NULL,
  PRIMARY KEY (`idConsommation`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `consommation`
--

INSERT INTO `consommation` (`idConsommation`, `DateConsommation`, `notesConsommation`) VALUES
(11, '2020-05-01', 'tr??s tr??s bon'),
(12, '2020-01-17', 'j\'aime moins');

-- --------------------------------------------------------

--
-- Table structure for table `emplacement`
--

DROP TABLE IF EXISTS `emplacement`;
CREATE TABLE IF NOT EXISTS `emplacement` (
  `idEmplacement` int(11) NOT NULL AUTO_INCREMENT,
  `nomRangement` varchar(100) NOT NULL,
  `rang` char(1) NOT NULL,
  `colonne` char(1) NOT NULL,
  PRIMARY KEY (`idEmplacement`),
  KEY `nomRangement` (`nomRangement`)
) ENGINE=InnoDB AUTO_INCREMENT=211 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `emplacement`
--

INSERT INTO `emplacement` (`idEmplacement`, `nomRangement`, `rang`, `colonne`) VALUES
(1, 'Etag??re A (60)', 'A', '1'),
(2, 'Etag??re A (60)', 'A', '2'),
(3, 'Etag??re A (60)', 'A', '3'),
(4, 'Etag??re A (60)', 'A', '4'),
(5, 'Etag??re A (60)', 'A', '5'),
(6, 'Etag??re A (60)', 'A', '6'),
(7, 'Etag??re A (60)', 'B', '1'),
(8, 'Etag??re A (60)', 'B', '2'),
(9, 'Etag??re A (60)', 'B', '3'),
(10, 'Etag??re A (60)', 'B', '4'),
(11, 'Etag??re A (60)', 'B', '5'),
(12, 'Etag??re A (60)', 'B', '6'),
(13, 'Etag??re A (60)', 'C', '1'),
(14, 'Etag??re A (60)', 'C', '2'),
(15, 'Etag??re A (60)', 'C', '3'),
(16, 'Etag??re A (60)', 'C', '4'),
(17, 'Etag??re A (60)', 'C', '5'),
(18, 'Etag??re A (60)', 'C', '6'),
(19, 'Etag??re A (60)', 'D', '1'),
(20, 'Etag??re A (60)', 'D', '2'),
(21, 'Etag??re A (60)', 'D', '3'),
(22, 'Etag??re A (60)', 'D', '4'),
(23, 'Etag??re A (60)', 'D', '5'),
(24, 'Etag??re A (60)', 'D', '6'),
(25, 'Etag??re A (60)', 'E', '1'),
(26, 'Etag??re A (60)', 'E', '2'),
(27, 'Etag??re A (60)', 'E', '3'),
(28, 'Etag??re A (60)', 'E', '4'),
(29, 'Etag??re A (60)', 'E', '5'),
(30, 'Etag??re A (60)', 'E', '6'),
(31, 'Etag??re A (60)', 'F', '1'),
(32, 'Etag??re A (60)', 'F', '2'),
(33, 'Etag??re A (60)', 'F', '3'),
(34, 'Etag??re A (60)', 'F', '4'),
(35, 'Etag??re A (60)', 'F', '5'),
(36, 'Etag??re A (60)', 'F', '6'),
(37, 'Etag??re A (60)', 'G', '1'),
(38, 'Etag??re A (60)', 'G', '2'),
(39, 'Etag??re A (60)', 'G', '3'),
(40, 'Etag??re A (60)', 'G', '4'),
(41, 'Etag??re A (60)', 'G', '5'),
(42, 'Etag??re A (60)', 'G', '6'),
(43, 'Etag??re A (60)', 'H', '1'),
(44, 'Etag??re A (60)', 'H', '2'),
(45, 'Etag??re A (60)', 'H', '3'),
(46, 'Etag??re A (60)', 'H', '4'),
(47, 'Etag??re A (60)', 'H', '5'),
(48, 'Etag??re A (60)', 'H', '6'),
(49, 'Etag??re A (60)', 'I', '1'),
(50, 'Etag??re A (60)', 'I', '2'),
(51, 'Etag??re A (60)', 'I', '3'),
(52, 'Etag??re A (60)', 'I', '4'),
(53, 'Etag??re A (60)', 'I', '5'),
(54, 'Etag??re A (60)', 'I', '6'),
(55, 'Etag??re A (60)', 'J', '1'),
(56, 'Etag??re A (60)', 'J', '2'),
(57, 'Etag??re A (60)', 'J', '3'),
(58, 'Etag??re A (60)', 'J', '4'),
(59, 'Etag??re A (60)', 'J', '5'),
(60, 'Etag??re A (60)', 'J', '6'),
(61, 'Etag??re B (60)', 'A', '1'),
(62, 'Etag??re B (60)', 'A', '2'),
(63, 'Etag??re B (60)', 'A', '3'),
(64, 'Etag??re B (60)', 'A', '4'),
(65, 'Etag??re B (60)', 'A', '5'),
(66, 'Etag??re B (60)', 'A', '6'),
(67, 'Etag??re B (60)', 'B', '1'),
(68, 'Etag??re B (60)', 'B', '2'),
(69, 'Etag??re B (60)', 'B', '3'),
(70, 'Etag??re B (60)', 'B', '4'),
(71, 'Etag??re B (60)', 'B', '5'),
(72, 'Etag??re B (60)', 'B', '6'),
(73, 'Etag??re B (60)', 'C', '1'),
(74, 'Etag??re B (60)', 'C', '2'),
(75, 'Etag??re B (60)', 'C', '3'),
(76, 'Etag??re B (60)', 'C', '4'),
(77, 'Etag??re B (60)', 'C', '5'),
(78, 'Etag??re B (60)', 'C', '6'),
(79, 'Etag??re B (60)', 'D', '1'),
(80, 'Etag??re B (60)', 'D', '2'),
(81, 'Etag??re B (60)', 'D', '3'),
(82, 'Etag??re B (60)', 'D', '4'),
(83, 'Etag??re B (60)', 'D', '5'),
(84, 'Etag??re B (60)', 'D', '6'),
(85, 'Etag??re B (60)', 'E', '1'),
(86, 'Etag??re B (60)', 'E', '2'),
(87, 'Etag??re B (60)', 'E', '3'),
(88, 'Etag??re B (60)', 'E', '4'),
(89, 'Etag??re B (60)', 'E', '5'),
(90, 'Etag??re B (60)', 'E', '6'),
(91, 'Etag??re B (60)', 'F', '1'),
(92, 'Etag??re B (60)', 'F', '2'),
(93, 'Etag??re B (60)', 'F', '3'),
(94, 'Etag??re B (60)', 'F', '4'),
(95, 'Etag??re B (60)', 'F', '5'),
(96, 'Etag??re B (60)', 'F', '6'),
(97, 'Etag??re B (60)', 'G', '1'),
(98, 'Etag??re B (60)', 'G', '2'),
(99, 'Etag??re B (60)', 'G', '3'),
(100, 'Etag??re B (60)', 'G', '4'),
(101, 'Etag??re B (60)', 'G', '5'),
(102, 'Etag??re B (60)', 'G', '6'),
(103, 'Etag??re B (60)', 'H', '1'),
(104, 'Etag??re B (60)', 'H', '2'),
(105, 'Etag??re B (60)', 'H', '3'),
(106, 'Etag??re B (60)', 'H', '4'),
(107, 'Etag??re B (60)', 'H', '5'),
(108, 'Etag??re B (60)', 'H', '6'),
(109, 'Etag??re B (60)', 'I', '1'),
(110, 'Etag??re B (60)', 'I', '2'),
(111, 'Etag??re B (60)', 'I', '3'),
(112, 'Etag??re B (60)', 'I', '4'),
(113, 'Etag??re B (60)', 'I', '5'),
(114, 'Etag??re B (60)', 'I', '6'),
(115, 'Etag??re B (60)', 'J', '1'),
(116, 'Etag??re B (60)', 'J', '2'),
(117, 'Etag??re B (60)', 'J', '3'),
(118, 'Etag??re B (60)', 'J', '4'),
(119, 'Etag??re B (60)', 'J', '5'),
(120, 'Etag??re B (60)', 'J', '6'),
(121, 'Etag??re C (50)', 'A', '1'),
(122, 'Etag??re C (50)', 'A', '2'),
(123, 'Etag??re C (50)', 'A', '3'),
(124, 'Etag??re C (50)', 'A', '4'),
(125, 'Etag??re C (50)', 'A', '5'),
(126, 'Etag??re C (50)', 'B', '1'),
(127, 'Etag??re C (50)', 'B', '2'),
(128, 'Etag??re C (50)', 'B', '3'),
(129, 'Etag??re C (50)', 'B', '4'),
(130, 'Etag??re C (50)', 'B', '5'),
(131, 'Etag??re C (50)', 'C', '1'),
(132, 'Etag??re C (50)', 'C', '2'),
(133, 'Etag??re C (50)', 'C', '3'),
(134, 'Etag??re C (50)', 'C', '4'),
(135, 'Etag??re C (50)', 'C', '5'),
(136, 'Etag??re C (50)', 'D', '1'),
(137, 'Etag??re C (50)', 'D', '2'),
(138, 'Etag??re C (50)', 'D', '3'),
(139, 'Etag??re C (50)', 'D', '4'),
(140, 'Etag??re C (50)', 'D', '5'),
(141, 'Etag??re C (50)', 'E', '1'),
(142, 'Etag??re C (50)', 'E', '2'),
(143, 'Etag??re C (50)', 'E', '3'),
(144, 'Etag??re C (50)', 'E', '4'),
(145, 'Etag??re C (50)', 'E', '5'),
(146, 'Etag??re C (50)', 'F', '1'),
(147, 'Etag??re C (50)', 'F', '2'),
(148, 'Etag??re C (50)', 'F', '3'),
(149, 'Etag??re C (50)', 'F', '4'),
(150, 'Etag??re C (50)', 'F', '5'),
(151, 'Etag??re C (50)', 'G', '1'),
(152, 'Etag??re C (50)', 'G', '2'),
(153, 'Etag??re C (50)', 'G', '3'),
(154, 'Etag??re C (50)', 'G', '4'),
(155, 'Etag??re C (50)', 'G', '5'),
(156, 'Etag??re C (50)', 'H', '1'),
(157, 'Etag??re C (50)', 'H', '2'),
(158, 'Etag??re C (50)', 'H', '3'),
(159, 'Etag??re C (50)', 'H', '4'),
(160, 'Etag??re C (50)', 'H', '5'),
(161, 'Etag??re C (50)', 'I', '1'),
(162, 'Etag??re C (50)', 'I', '2'),
(163, 'Etag??re C (50)', 'I', '3'),
(164, 'Etag??re C (50)', 'I', '4'),
(165, 'Etag??re C (50)', 'I', '5'),
(166, 'Etag??re C (50)', 'J', '1'),
(167, 'Etag??re C (50)', 'J', '2'),
(168, 'Etag??re C (50)', 'J', '3'),
(169, 'Etag??re C (50)', 'J', '4'),
(170, 'Etag??re C (50)', 'J', '5'),
(171, 'Garde (40)', 'A', '1'),
(172, 'Garde (40)', 'A', '2'),
(173, 'Garde (40)', 'A', '3'),
(174, 'Garde (40)', 'A', '4'),
(175, 'Garde (40)', 'A', '5'),
(176, 'Garde (40)', 'B', '1'),
(177, 'Garde (40)', 'B', '2'),
(178, 'Garde (40)', 'B', '3'),
(179, 'Garde (40)', 'B', '4'),
(180, 'Garde (40)', 'B', '5'),
(181, 'Garde (40)', 'C', '1'),
(182, 'Garde (40)', 'C', '2'),
(183, 'Garde (40)', 'C', '3'),
(184, 'Garde (40)', 'C', '4'),
(185, 'Garde (40)', 'C', '5'),
(186, 'Garde (40)', 'D', '1'),
(187, 'Garde (40)', 'D', '2'),
(188, 'Garde (40)', 'D', '3'),
(189, 'Garde (40)', 'D', '4'),
(190, 'Garde (40)', 'D', '5'),
(191, 'Garde (40)', 'E', '1'),
(192, 'Garde (40)', 'E', '2'),
(193, 'Garde (40)', 'E', '3'),
(194, 'Garde (40)', 'E', '4'),
(195, 'Garde (40)', 'E', '5'),
(196, 'Garde (40)', 'F', '1'),
(197, 'Garde (40)', 'F', '2'),
(198, 'Garde (40)', 'F', '3'),
(199, 'Garde (40)', 'F', '4'),
(200, 'Garde (40)', 'F', '5'),
(201, 'Garde (40)', 'G', '1'),
(202, 'Garde (40)', 'G', '2'),
(203, 'Garde (40)', 'G', '3'),
(204, 'Garde (40)', 'G', '4'),
(205, 'Garde (40)', 'G', '5'),
(206, 'Garde (40)', 'H', '1'),
(207, 'Garde (40)', 'H', '2'),
(208, 'Garde (40)', 'H', '3'),
(209, 'Garde (40)', 'H', '4'),
(210, 'Garde (40)', 'H', '5');

-- --------------------------------------------------------

--
-- Table structure for table `fournisseur`
--

DROP TABLE IF EXISTS `fournisseur`;
CREATE TABLE IF NOT EXISTS `fournisseur` (
  `idFournisseur` int(11) NOT NULL AUTO_INCREMENT,
  `nomFournisseur` varchar(200) NOT NULL,
  `rueFournisseur` varchar(200) DEFAULT NULL,
  `numeroFournisseur` varchar(10) DEFAULT NULL,
  `CPFournisseur` varchar(10) NOT NULL,
  `localiteFournisseur` varchar(250) NOT NULL,
  `idPays` int(11) NOT NULL,
  PRIMARY KEY (`idFournisseur`),
  KEY `idPays` (`idPays`),
  KEY `nomFournisseur` (`nomFournisseur`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `fournisseur`
--

INSERT INTO `fournisseur` (`idFournisseur`, `nomFournisseur`, `rueFournisseur`, `numeroFournisseur`, `CPFournisseur`, `localiteFournisseur`, `idPays`) VALUES
(1, 'Licata Vini ', 'Duifhuisweg', '12', '3590', 'Diepenbeek', 16),
(2, 'Avina', 'rue des semailles', '1A', '4400', 'Flemalle', 16),
(3, 'Cora', 'chauss??e de Tongres', '269', '4000', 'Rocourt', 16),
(4, 'Delhaize', 'rue de Rotheux', '12', '4100', 'Seraing', 16),
(5, 'Weinpalais', 'Gutenbergstrasse', '8', '50823', 'K??ln', 65),
(6, 'Avenue des vins', 'rue Guillaume Tell', '10', '75017', 'Paris', 60),
(7, 'Vinatis', '??Avenue du Pr?? de Challes', '6', '74940', 'Annecy Le Vieux', 60),
(8, 'Nicolas', 'Rue du Pot d\'Or', '10a', '4000', 'Li??ge', 16),
(9, 'Pancole', 'Via Montecarlo', '29', 'AR', 'San Giovanni Valdarno', 84),
(10, 'Agriturismo Castello di Querceto', 'Via Alessandro Fran??ois', '2', '50022', 'Greve in Chianti', 84);

-- --------------------------------------------------------

--
-- Table structure for table `pays`
--

DROP TABLE IF EXISTS `pays`;
CREATE TABLE IF NOT EXISTS `pays` (
  `idPays` int(11) NOT NULL AUTO_INCREMENT,
  `nomPays` varchar(100) NOT NULL,
  PRIMARY KEY (`idPays`),
  KEY `nomPays` (`nomPays`)
) ENGINE=InnoDB AUTO_INCREMENT=195 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `pays`
--

INSERT INTO `pays` (`idPays`, `nomPays`) VALUES
(1, 'Afghanistan'),
(160, 'Afrique du Sud'),
(2, 'Albanie'),
(3, 'Alg??rie'),
(65, 'Allemagne'),
(4, 'Andorre'),
(5, 'Angola'),
(6, 'Antigua-et-Barbuda'),
(151, 'Arabie Saoudite'),
(8, 'Argentine'),
(14, 'Arm??nie'),
(9, 'Australie'),
(10, 'Autriche'),
(7, 'Azerba??djan'),
(11, 'Bahamas'),
(12, 'Bahre??n'),
(13, 'Bangladesh'),
(15, 'Barbade'),
(28, 'B??larus'),
(16, 'Belgique'),
(22, 'Belize'),
(48, 'B??nin'),
(17, 'Bhoutan'),
(18, 'Bolivie'),
(19, 'Bosnie-Herz??govine'),
(20, 'Botswana'),
(21, 'Br??sil'),
(24, 'Brun??i Darussalam'),
(25, 'Bulgarie'),
(187, 'Burkina Faso'),
(27, 'Burundi'),
(29, 'Cambodge'),
(30, 'Cameroun'),
(31, 'Canada'),
(32, 'Cap-vert'),
(36, 'Chili'),
(37, 'Chine'),
(46, 'Chypre'),
(39, 'Colombie'),
(40, 'Comores'),
(43, 'Costa Rica'),
(85, 'C??te dIvoire'),
(44, 'Croatie'),
(45, 'Cuba'),
(49, 'Danemark'),
(61, 'Djibouti'),
(50, 'Dominique'),
(183, '??gypte'),
(53, 'El Salvador'),
(175, '??mirats Arabes Unis'),
(52, '??quateur'),
(56, '??rythr??e'),
(162, 'Espagne'),
(57, 'Estonie'),
(129, '??tats F??d??r??s de Micron??sie'),
(186, '??tats-Unis'),
(55, '??thiopie'),
(144, 'F??d??ration de Russie'),
(58, 'Fidji'),
(59, 'Finlande'),
(60, 'France'),
(62, 'Gabon'),
(64, 'Gambie'),
(63, 'G??orgie'),
(66, 'Ghana'),
(68, 'Gr??ce'),
(69, 'Grenade'),
(70, 'Guatemala'),
(71, 'Guin??e'),
(54, 'Guin??e ??quatoriale'),
(140, 'Guin??e-Bissau'),
(72, 'Guyana'),
(73, 'Ha??ti'),
(75, 'Honduras'),
(76, 'Hongrie'),
(130, '??les Marshall'),
(23, '??les Salomon'),
(78, 'Inde'),
(79, 'Indon??sie'),
(81, 'Iraq'),
(82, 'Irlande'),
(77, 'Islande'),
(83, 'Isra??l'),
(84, 'Italie'),
(100, 'Jamahiriya Arabe Libyenne'),
(86, 'Jama??que'),
(87, 'Japon'),
(89, 'Jordanie'),
(88, 'Kazakhstan'),
(90, 'Kenya'),
(94, 'Kirghizistan'),
(67, 'Kiribati'),
(93, 'Kowe??t'),
(97, 'Lesotho'),
(98, 'Lettonie'),
(182, 'Lex-R??publique Yougoslave de Mac??doine'),
(96, 'Liban'),
(99, 'Lib??ria'),
(101, 'Liechtenstein'),
(102, 'Lituanie'),
(103, 'Luxembourg'),
(104, 'Madagascar'),
(106, 'Malaisie'),
(105, 'Malawi'),
(107, 'Maldives'),
(108, 'Mali'),
(109, 'Malte'),
(116, 'Maroc'),
(111, 'Maurice'),
(110, 'Mauritanie'),
(112, 'Mexique'),
(113, 'Monaco'),
(114, 'Mongolie'),
(117, 'Mozambique'),
(26, 'Myanmar'),
(119, 'Namibie'),
(120, 'Nauru'),
(121, 'N??pal'),
(125, 'Nicaragua'),
(126, 'Niger'),
(127, 'Nig??ria'),
(128, 'Norv??ge'),
(124, 'Nouvelle-Z??lande'),
(118, 'Oman'),
(180, 'Ouganda'),
(189, 'Ouzb??kistan'),
(132, 'Pakistan'),
(131, 'Palaos'),
(133, 'Panama'),
(134, 'Papouasie-Nouvelle-Guin??e'),
(135, 'Paraguay'),
(122, 'Pays-Bas'),
(136, 'P??rou'),
(137, 'Philippines'),
(138, 'Pologne'),
(139, 'Portugal'),
(142, 'Qatar'),
(169, 'R??publique Arabe Syrienne'),
(33, 'R??publique Centrafricaine'),
(92, 'R??publique de Cor??e'),
(115, 'R??publique de Moldova'),
(42, 'R??publique D??mocratique du Congo'),
(95, 'R??publique D??mocratique Populaire Lao'),
(51, 'R??publique Dominicaine'),
(41, 'R??publique du Congo'),
(80, 'R??publique Islamique dIran'),
(91, 'R??publique Populaire D??mocratique de Cor??e'),
(47, 'R??publique Tch??que'),
(185, 'R??publique-Unie de Tanzanie'),
(143, 'Roumanie'),
(184, 'Royaume-Uni'),
(145, 'Rwanda'),
(163, 'Sahara Occidental'),
(146, 'Saint-Kitts-et-Nevis'),
(149, 'Saint-Marin'),
(74, 'Saint-Si??ge ??tat de la Cit?? du Vatican)'),
(148, 'Saint-Vincent-et-les Grenadines'),
(147, 'Sainte-Lucie'),
(191, 'Samoa'),
(150, 'Sao Tom??-et-Principe'),
(152, 'S??n??gal'),
(193, 'Serbie-et-Mont??n??gro'),
(153, 'Seychelles'),
(154, 'Sierra Leone'),
(155, 'Singapour'),
(156, 'Slovaquie'),
(158, 'Slov??nie'),
(159, 'Somalie'),
(164, 'Soudan'),
(34, 'Sri Lanka'),
(167, 'Su??de'),
(168, 'Suisse'),
(165, 'Suriname'),
(166, 'Swaziland'),
(170, 'Tadjikistan'),
(38, 'Ta??wan'),
(35, 'Tchad'),
(171, 'Tha??lande'),
(141, 'Timor-Leste'),
(172, 'Togo'),
(173, 'Tonga'),
(174, 'Trinit??-et-Tobago'),
(176, 'Tunisie'),
(178, 'Turkm??nistan'),
(177, 'Turquie'),
(179, 'Tuvalu'),
(181, 'Ukraine'),
(188, 'Uruguay'),
(123, 'Vanuatu'),
(190, 'Venezuela'),
(157, 'Viet Nam'),
(192, 'Y??men'),
(194, 'Zambie'),
(161, 'Zimbabwe');

-- --------------------------------------------------------

--
-- Table structure for table `producteur`
--

DROP TABLE IF EXISTS `producteur`;
CREATE TABLE IF NOT EXISTS `producteur` (
  `idProducteur` int(11) NOT NULL AUTO_INCREMENT,
  `nomProducteur` varchar(250) NOT NULL,
  `rueProducteur` varchar(250) DEFAULT NULL,
  `numeroProducteur` varchar(10) DEFAULT NULL,
  `CPProducteur` varchar(10) NOT NULL,
  `localiteProducteur` varchar(200) NOT NULL,
  `idPays` int(11) NOT NULL,
  PRIMARY KEY (`idProducteur`),
  KEY `idPays` (`idPays`)
) ENGINE=InnoDB AUTO_INCREMENT=41 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `producteur`
--

INSERT INTO `producteur` (`idProducteur`, `nomProducteur`, `rueProducteur`, `numeroProducteur`, `CPProducteur`, `localiteProducteur`, `idPays`) VALUES
(37, 'de mour', 'saint-laurent-des-combes', '', '33330', 'bordeaux', 60),
(38, 'frank cornelissen', '', '', '61234', 'solicchiata', 84),
(39, 'chateau tayac', 'soussans', '', '33460', 'tayac', 60),
(40, 'bogedas vina elena', 'estrecho de marin', '', '30520', 'jumilla', 162);

-- --------------------------------------------------------

--
-- Table structure for table `vin`
--

DROP TABLE IF EXISTS `vin`;
CREATE TABLE IF NOT EXISTS `vin` (
  `idVin` int(11) NOT NULL AUTO_INCREMENT,
  `nomCuvee` varchar(250) NOT NULL,
  `appellation` varchar(250) NOT NULL,
  `nomRegion` varchar(100) DEFAULT NULL,
  `idPays` int(11) NOT NULL,
  `couleur` varchar(20) NOT NULL,
  `idProducteur` int(11) NOT NULL,
  `garde` char(4) DEFAULT NULL,
  `bio` tinyint(1) NOT NULL,
  `millesime` int(11) NOT NULL,
  PRIMARY KEY (`idVin`),
  KEY `idPays` (`idPays`),
  KEY `idProducteur` (`idProducteur`),
  KEY `appellation` (`appellation`),
  KEY `nomRegion` (`nomRegion`),
  KEY `couleur` (`couleur`),
  KEY `millesime` (`millesime`)
) ENGINE=InnoDB AUTO_INCREMENT=80 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `vin`
--

INSERT INTO `vin` (`idVin`, `nomCuvee`, `appellation`, `nomRegion`, `idPays`, `couleur`, `idProducteur`, `garde`, `bio`, `millesime`) VALUES
(62, 'chateau tour baladoz', 'aoc - saint-emilion grand cru', 'bordeaux', 60, 'rgl', 37, '0815', 0, 2016),
(64, 'munjebel rosso monte colla', 'igp - terre siciliane', 'sicille', 84, 'rgt', 38, '0102', 1, 2017),
(65, 'margaux', 'aoc - medoc', 'bordeaux', 60, 'rgl', 39, '0310', 0, 2009),
(66, 'familia pacheco', 'familia', 'jumilla', 162, 'ble', 40, '0000', 0, 2012),
(67, 'la croix de saint clement', 'aoc - bordeaux blanc', 'bordeaux', 60, 'blt', 37, '0304', 0, 2008),
(68, 'prince rubis', 'aoc - bordeaux blanc', 'bordeaux', 60, 'bll', 37, '0102', 0, 2019),
(69, 'baronne ghislaine', 'aoc - haut medoc', 'haut medoc', 60, 'rgt', 37, '0812', 1, 2006),
(70, 'marquise romane', 'aoc - saint-julien', 'saint-julien', 60, 'rgt', 37, '0000', 0, 2014),
(71, 'les combes de la croizille', 'aoc - saint-emilion grand cru', 'bordeaux', 60, 'rgt', 37, '0815', 0, 2006),
(72, 'le chamane de saint m', 'aoc - saint-emilion grand cru', 'bordeaux', 60, 'rgl', 37, '0510', 1, 2004),
(73, 'les grottes d\'arcis', 'aoc - saint-emilion grand cru', 'bordeaux', 60, 'rgl', 37, '0510', 1, 2011),
(74, 'munjebel rosso classico', 'igp - terre siciliane', 'sicile', 84, 'rse', 38, '0000', 1, 2001),
(75, 'munjebel pa', 'igp - terre siciliane', 'sicile', 84, 'rse', 38, '0205', 0, 2014),
(76, 'munjebel cr', 'igp - terre siciliane', 'sicile', 84, 'rst', 38, '0210', 1, 2016),
(77, 'munjebel cs', 'igp - terre siciliane', 'sicile', 84, 'rse', 38, '0108', 0, 2016),
(78, 'munjebel va', 'igp - terre siciliane', 'sicile', 84, 'ble', 38, '0210', 0, 2004),
(79, 'munjebel bb', 'igp - terre siciliane', 'sicile', 84, 'rse', 38, '0104', 1, 2019);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `bouteille`
--
ALTER TABLE `bouteille`
  ADD CONSTRAINT `bouteille_ibfk_1` FOREIGN KEY (`idVin`) REFERENCES `vin` (`idVin`),
  ADD CONSTRAINT `bouteille_ibfk_2` FOREIGN KEY (`idEmplacement`) REFERENCES `emplacement` (`idEmplacement`),
  ADD CONSTRAINT `bouteille_ibfk_3` FOREIGN KEY (`idConsommation`) REFERENCES `consommation` (`idConsommation`),
  ADD CONSTRAINT `bouteille_ibfk_4` FOREIGN KEY (`idFournisseur`) REFERENCES `fournisseur` (`idFournisseur`);

--
-- Constraints for table `fournisseur`
--
ALTER TABLE `fournisseur`
  ADD CONSTRAINT `fournisseur_ibfk_1` FOREIGN KEY (`idPays`) REFERENCES `pays` (`idPays`);

--
-- Constraints for table `producteur`
--
ALTER TABLE `producteur`
  ADD CONSTRAINT `producteur_ibfk_1` FOREIGN KEY (`idPays`) REFERENCES `pays` (`idPays`);

--
-- Constraints for table `vin`
--
ALTER TABLE `vin`
  ADD CONSTRAINT `vin_ibfk_1` FOREIGN KEY (`idPays`) REFERENCES `pays` (`idPays`),
  ADD CONSTRAINT `vin_ibfk_2` FOREIGN KEY (`idProducteur`) REFERENCES `producteur` (`idProducteur`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
