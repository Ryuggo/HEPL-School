<?xml version="1.0" encoding="iso-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
<body>
	<h2>Mes films</h2>

	<table border="1">
		<tr bgcolor="red">
			<th>id</th>
			<th>Titre</th>
			<th>Titre original</th>
			<th>Date de sortie</th>
			<th>Statut</th>
			<th>Note moyenne</th>
			<th>Nombre vote</th>
			<th>Nombre diffustion</th>
			<th>Certification</th>
			<th>Chemin acces image</th>
			<th>Budget</th>
			<th>Description</th>
			<th>Genre</th>
			<th>Directeurs</th>
			<th>Acteurs</th>
		</tr>
		<xsl:for-each select="films/film">
		<tr>
			<td><xsl:value-of select="id"/></td>
			<td><xsl:value-of select="title"/></td>
			<td><xsl:value-of select="originalTitle"/></td>
			<td><xsl:value-of select="releaseDate"/></td>
			<td><xsl:value-of select="status"/></td>
			<td><xsl:value-of select="voteAverage"/></td>
			<td><xsl:value-of select="voteCount"/></td>
			<td><xsl:value-of select="runtime"/></td>
			<td><xsl:value-of select="certification"/></td>
			<td><xsl:value-of select="posterPath"/></td>
			<td><xsl:value-of select="budget"/></td>
			<td><xsl:value-of select="tagline"/></td>
			<td>
				<xsl:for-each select="genres/genre">
					<p><xsl:value-of select="idg"/>
					<xsl:value-of select="nameg"/></p>
				</xsl:for-each>
			</td>
			<td>
				<xsl:for-each select="directors/director">
					<p><xsl:value-of select="idd"/>
					<xsl:value-of select="named"/></p>
				</xsl:for-each>
			</td>
			<td>
				<xsl:for-each select="actors/actor">
					<p><xsl:value-of select="ida"/>
					<xsl:value-of select="namea"/>
					<xsl:value-of select="caratera"/></p>
				</xsl:for-each>
			</td>
		</tr>
		</xsl:for-each>
	</table>
</body>
</html>
</xsl:template>
</xsl:stylesheet>