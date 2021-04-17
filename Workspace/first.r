library(Seurat)
library(SeuratData)
library(ggplot2)
library(patchwork)
library(dplyr)
InstallData("stxBrain")
brain <- LoadData("stxBrain", type = "anterior1")
plot1 <- VlnPlot(brain, features = "nCount_Spatial", pt.size = 0.1) + NoLegend()
plot2 <- SpatialFeaturePlot(brain, features = "nCount_Spatial") + theme(legend.position = "right")
wrap_plots(plot1, plot2)
brain <- SCTransform(brain, assay = "Spatial", verbose = FALSE)
GetAssayData(object = brain, slot = "counts")
SpatialFeaturePlot(brain, features = c("Hpca", "Ttr"))
p1 <- SpatialFeaturePlot(brain, features = "Ttr", pt.size.factor = 1)
p2 <- SpatialFeaturePlot(brain, features = "Ttr", alpha = c(0.1, 1))
p1 + p2
brain_pca <- RunPCA(brain, assay = "SCT", verbose = FALSE)
brain_neighbors <- FindNeighbors(brain_pca, reduction = "pca", dims = 1:30)
brain_clusters <- FindClusters(brain_neighbors, verbose = FALSE)
brain_umap <- RunUMAP(brain_clusters, reduction = "pca", dims = 1:30)
p1 <- DimPlot(brain_umap, reduction = "umap", label = TRUE)
p2 <- SpatialDimPlot(brain_umap, label = TRUE, label.size = 3)
p1 + p2

data.table <- as.matrix(GetAssayData(brain, slot = "counts"))
write.csv(x=data.table, file='/home/nuwaisir/4-1/Thesis/test_out')



